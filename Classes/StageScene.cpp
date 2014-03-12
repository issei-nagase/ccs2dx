//
//  StageScene.cpp
//  ccs2dx
//
//  Created by nagase on 2014/03/10.
//
//
#include "StageScene.h"
#include "TitleScene.h"

//using namespace cocos2d;の略。cocos2dの名前空間を利用
USING_NS_CC;


Scene *Stage::createScene()
{
    
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Stage::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}

bool Stage::init()
{
    //////////////////////////////
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    
    //画面の座標関係の詳しい説明はここ http://www.cocos2d-x.org/wiki/Coordinate_System
    Size visibleSize = Director::getInstance()->getVisibleSize(); //画面のサイズを取得
    Point origin = Director::getInstance()->getVisibleOrigin();  //マルチレゾリューション対応がどうとか
    
    //背景を設置
    Sprite* background = Sprite::create("Rubik_cube.png");
    background->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    this->addChild(background, 0); //第2引数は表示順
    
    //pImg1を画面中央に配置
    Sprite* ball1 = Sprite::create("ball.png");
    ball1->setPosition(Point(
                             origin.x + visibleSize.width / 2,
                             origin.y + visibleSize.height / 2));
    this->addChild(ball1, 1);

    //pImg2を配置
    Sprite* ball2 = Sprite::create("ball.png");
    ball2->setPosition(
                       Point(origin.x + visibleSize.width / 2 - 300,
                             origin.y + visibleSize.height / 2 - 300));
    this->addChild(ball2, 1);
    
    //pImg1とpImg2の表示領域を取得
    Rect rect1 = ball1->boundingBox();
    Rect rect2 = ball2->boundingBox();
    
    //rect1（pImg1の表示領域）とrect2（pImg2の表示領域）が重なっているか
    if(rect1.intersectsRect(rect2))
    {
        CCLOG("rect1とrect2は重なってます");
    }else
    {
        CCLOG("rect1とrect2は重なってません");
    }
    
    //戻るボタンを設置
    auto backButton = MenuItemImage::create(
                                            "CloseNormal.png",  //表示
                                            "CloseSelected.png",  //タップ時の画像
                                            CC_CALLBACK_1(Stage::pushBack, this));
    
    backButton->setPosition(Point(origin.x + visibleSize.width - backButton->getContentSize().width/2 ,
                                  origin.y + backButton->getContentSize().height/2));
    
    //create menu, it's an autorelease object
    auto menu = Menu::create(backButton, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}

void Stage::pushBack(Object *pSender)
{
    // 遷移先の画面のインスタンス
    Scene *pScene = Title::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    //遷移実行  遷移時のアニメーション　http://study-cocos2d-x.info/scenelayer/55/
    Director::getInstance()->replaceScene(transition);
}