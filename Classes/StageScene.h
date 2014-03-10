//
//  StageScene.h
//  ccs2dx
//
//  Created by nagase on 2014/03/10.
//
//

#ifndef __ccs2dx__StageScene__
#define __ccs2dx__Stage

#include "cocos2d.h"

class Stage : public cocos2d::Layer
{
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    //初期化のメソッド
    virtual bool init();
    
    //create()を使えるようにしている。
    CREATE_FUNC(Stage);
    void pushBack(Object *pSender); //戻る
};

#endif /* defined(__ccs2dx__StageScene__) */
