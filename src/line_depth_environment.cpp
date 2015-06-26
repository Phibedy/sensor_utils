#include <sensor_utils/line_depth_environment.h>
#include <cmath>
#include <iostream>
LinedDepthEnvironment::LinedDepthEnvironment():xBuffer(0),m_stepLength(0),m_sensivity(0),m_minY(-INFINITY), m_maxY(INFINITY){
}

void LinedDepthEnvironment::set(float stepLength, float sensivity,float yMin, float yMax){
    m_stepLength = stepLength;
    m_sensivity = sensivity;
    m_minY = yMin;
    m_maxY = yMax;
}

bool LinedDepthEnvironment::add(float deltaX,float y){
    //std::cout <<"ANFANG" <<xBuffer << " "<< m_stepLength <<std::endl;
    xBuffer += deltaX;
    if(xBuffer < m_stepLength)
        return false;
    //limit the y-values
    if(y < m_minY)
        y = m_minY;
    if(y > m_maxY)
        y = m_maxY;
    //add values to the discrete vector
    //std::cout <<"Davor" <<xBuffer << " "<< m_stepLength <<std::endl;
    while(xBuffer > m_stepLength){
        m_distances.push_back(y);
        xBuffer -= m_stepLength;
        //std::cout <<"DRIN" <<xBuffer << " "<< m_stepLength <<std::endl;
    }
    //std::cout <<"DANACH" <<std::endl;
    //now the xBuffer should be negative as we substracted the stepLength one time to often -> add it again
    xBuffer += m_stepLength;
    return true;
}

/**
 * @brief draw
 * @param distanceInPixel how many meters one pixel is
 */
void LinedDepthEnvironment::draw(lms::imaging::Graphics *graphics,float distanceInPixel){
    std::cout << "draw START" << std::endl;
    float mul = distanceInPixel*m_stepLength;
    int xPadding = 20;
    graphics->setColor(lms::imaging::black);
    //draw all points
    for(int i = 0; i < ((int)m_distances.size())-1; i++){
        graphics->drawLine(xPadding+m_distances[i]*mul,i*mul,xPadding+m_distances[i+1]*mul,(i+1)*mul);
    }

    std::cout << "draw DAZWISCHEN" <<std::endl;
    //draw found parts
    //might be disturbing that the x-axis of the part is the y-axis of the image :)
    graphics->setColor(lms::imaging::blue);
    for(uint i = 0; i < parts.size(); i++){
        LineDepthSegment &p = parts[i];
        graphics->drawLine(xPadding+p.y*mul,p.startIndex*mul,xPadding + p.y*mul,p.endIndex*mul);
    }
}


void LinedDepthEnvironment::validate() const{
    const_cast<LinedDepthEnvironment*>(this)->validate();
}

void LinedDepthEnvironment::validate(){
    if(m_sensivity == 0 || m_distances.size() == 0){
        //TODO not sure what should happen :'(
        return;
    }
    int startSearch = 0;
    if(parts.size() > 0){
        startSearch = parts[parts.size()-1].endIndex+1;
    }
    float startY = m_distances[startSearch];

    for(uint i = startSearch+1; i < m_distances.size(); i++){
        if(abs(m_distances[i]-startY) > m_sensivity){
            //found new part
            parts.push_back(LineDepthSegment(startSearch,i,startSearch*m_stepLength, i*m_stepLength,startY));
            startSearch = i;
            startY = m_distances[i];
        }
    }
}


const std::vector<LinedDepthEnvironment::LineDepthSegment>& LinedDepthEnvironment::getParts() const{
    validate();
    return parts;
}
