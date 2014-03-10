//
//  TitleScene.cpp
//  ccs2dx
//
//  Created by nagase on 2014/03/08.
//
//

#include "TitleScene.h"
#include "StageScene.h"

#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene *Title::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = Title::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    return scene;
}

bool Title::init()
{
    // 1. super init first
    if (!Layer::init())
    {
        return false;
    }
    // 画面の座標関係の詳しい説明はここ
    // http://www.cocos2d-x.org/wiki/Coordinate_System
    Size visibleSize = Director::getInstance()->getVisibleSize();
    Point origin = Director::getInstance()->getVisibleOrigin();  //マルチレゾリューション対応がどうとか
    //背景を設置
    Sprite* background = Sprite::create("HelloWorld.png");
    background->setPosition(Point(origin.x + visibleSize.width / 2, origin.y + visibleSize.height / 2));
    this->addChild(background, 0); //第2引数は表示順
    // タイトルラベル表示
    auto label_title = LabelTTF::create("タイトル", "HiraKakuProN-W6", 30);
    label_title->setPosition(Point(origin.x + visibleSize.width / 2,
                                   origin.y + visibleSize.height - label_title->getContentSize().height));
    this->addChild(label_title, 1);
    // スタートボタン表示
    auto startButton = MenuItemImage::create("CloseNormal.png",                         // 通常状態の画像
                                             "CloseSelected.png",                       // 押下状態の画像
                                             CC_CALLBACK_1(Title::pushStart, this));    // 押下時のイベント
    startButton->setPosition(Point(origin.x + visibleSize.width - startButton->getContentSize().width / 2,
                                   origin.y + startButton->getContentSize().height/2));
    
    // create menu, it's an autorelease
    auto menu = Menu::create(startButton, NULL);
    menu->setPosition(Point::ZERO);
    this->addChild(menu, 1);
    
    return true;
}

void Title::pushStart(Object *pSender)
{
    // 効果音
    //CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("ComedyWhistle.caf");
    
    
    // 遷移先の画面のインスタンス
    Scene *pScene = Stage::createScene();
    
    // 0.5秒かけてフェードアウトしながら次の画面に遷移します
    //    引数１:フィードの時間
    //    引数２：移動先のシーン
    //    引数３：フィードの色（オプション）
    TransitionFade* transition = TransitionFade::create(0.5f, pScene);
    
    //遷移実行  遷移時のアニメーション　http://study-cocos2d-x.info/scenelayer/55/
    Director::getInstance()->replaceScene(transition);
}