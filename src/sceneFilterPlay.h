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


#ifndef __sonicTag2NB__sceneFilterPlay__
#define __sonicTag2NB__sceneFilterPlay__

#include <iostream>
#include "baseScene.h"
#include "ofxMaxim.h"
#include <vector>
#include "visualiser.h"
#include "geomFunctions.h"
#include "EAIT.h"
#include "baseScene.h"
#include "RadialScratchSurface.h"

using namespace std;

class sceneFilterPlay : public baseScene {
public:
    void setup(sharedDataContainer *data);
    void update();
    void audioRequested( float * output, int bufferSize, int nChannels );
    void beginScene();
    void endScene();
    string getTitle() {return string("Filter Play");}
    void handleInterfaceEvent(int id, int eventTypeId, EAVIGUI::InterfaceObject *object);
protected:
    maxiSVF filt;
    float sigAvg;
    EAVIGUI::RadialScratchSurface *surface;
    float freq,res;
private:
    
};





#endif /* defined(__sonicTag2NB__sceneFilterPlay__) */
