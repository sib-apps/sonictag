/*
 This file is part of 'Sonic Tag'.
 This software is released under a simplified BSD license, modified for non-commercial use only.
 
 Copyright (c) 2013, M.Grierson, Embodied AudioVisual Interaction Group, Goldsmiths, University of London
 
 All rights reserved.
 
 Redistribution and use in source and binary forms, with or without
 modification, are permitted provided that the following conditions are
 met:
 
 * Redistributions of source code must retain the above copyright
 notice, this list of conditions and the following disclaimer.
 * Redistributions in binary form must reproduce the above
 copyright notice, this list of conditions and the following disclaimer
 in the documentation and/or other materials provided with the
 distribution.
 * Any redistribution, use, or modification is done solely for
 personal benefit and not for any commercial purpose or for monetary
 gain
 
 THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 
 For further information:
 http://eavi.goldsmithsdigital.com/sound-image-and-brain/
 http://eavi.goldsmithsdigital.com/sonic-tag/
 
 */


#ifndef sonicTag2_Smoothing_h
#define sonicTag2_Smoothing_h

#include <vector>

namespace EAIT {
    
    template<class T>
    class MovingAverage {
    public:
        MovingAverage() {
            MovingAverage(1,0);            
        }
        MovingAverage(int size, T fillValue=0.0) {
            values.resize(size, fillValue);
            index = 0;
            sampleSize = size;
            cachedValue = 0;
            cacheInvalid = true;            
        }
        
        inline void addSample(T s) {
            values[index] = s;
            index++;
            if(index == sampleSize) index = 0;
            cacheInvalid = true;
        }
        
        inline virtual T value() {
            if (cacheInvalid) {
                T total = 0;
                for(int i = 0; i < sampleSize; i++) {
                    total += values[i];
                }
                cachedValue = total / (T) sampleSize;
                cacheInvalid = false;
            }
            return cachedValue;
        }
        
        void resize(int size) {
            index = 0;
            values.resize(size, 0);
            sampleSize = size;
            cacheInvalid = true;            
        }
        
        void fillWith(T val) {
            for(int i = 0; i < sampleSize; i++) {
                values[i] = val;
            }	
            cacheInvalid = true;            
        }
        
        inline int size() {return values.size();}
    protected:
        std::vector<T> values;
        int index;
        int sampleSize;
        bool cacheInvalid;
        T cachedValue;
    };
    
    typedef MovingAverage<float> MovingAverageF;
    typedef MovingAverage<double> MovingAverageD;
    
    template <class T>
    class MovingRMS : public MovingAverage<T> {
    public:
        MovingRMS():MovingAverage<T>(){};
        MovingRMS(int size, T fillValue=0.0):MovingAverage<T>(size, fillValue){};
        
        T value() {
            if (MovingAverage<T>::cacheInvalid) {
                T total = 0;
                for(int i = 0; i < MovingAverage<T>::sampleSize; i++) {
                    total += (MovingAverage<T>::values[i] * MovingAverage<T>::values[i]);
                }
                MovingAverage<T>::cachedValue = sqrt(total / (T) MovingAverage<T>::sampleSize);
                MovingAverage<T>::cacheInvalid = false;
            }
            return MovingAverage<T>::cachedValue;
            
        }
    };
    
    typedef MovingRMS<float> MovingRMSF;
    typedef MovingRMS<double> MovingRMSD;
    
};

#endif
