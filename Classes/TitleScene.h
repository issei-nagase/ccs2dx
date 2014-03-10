//
//  TitleScene.h
//  ccs2dx
//
//  Created by nagase on 2014/03/08.
//
//

#ifndef __ccs2dx__TitleScene__
#define __ccs2dx__TitleScene__

#include "cocos2d.h"

class Title : public cocos2d::Layer
{
public:
    static cocos2d::Scene* createScene();
    // initialize method
    virtual bool init();
    
    CREATE_FUNC(Title);
    void pushStart(Object *pSender);
};

#endif /* defined(__ccs2dx__TitleScene__) */
