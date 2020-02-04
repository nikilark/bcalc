import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Layouts 1.3
import QtQuick.Extras 1.4
import SwipeModule 1.0
import BiCalcModule 1.0

Window {
    id: mainwindow
    visible: true
    width: 720
    height: 1280
        Text{
            id: maintext
            property int step: 1
            anchors.top: parent.top
            height: parent.height/3
            width: parent.width
            horizontalAlignment: Text.AlignRight
            font {
                pixelSize: maintext.height-10
            }
            wrapMode: Text.Wrap
            text: "0"
            onTextChanged: {
                if(maintext.contentWidth>maintext.width*0.8&&maintext.contentHeight>maintext.height*1.1)
                    maintext.font.pixelSize/=2;
            }
        }
        Text {
         id : subtext
         anchors.top: maintext.bottom
         anchors.left: parent.left
         height: parent.height/6
         width: parent.width/5*4
         horizontalAlignment: Text.AlignRight
         text: ""
         font{
             pixelSize: subtext.height-10
         }
         wrapMode: Text.Wrap
         onTextChanged: {
             if(subtext.contentWidth>subtext.width*0.8&&subtext.contentHeight>subtext.height*1.1)
                 subtext.font.pixelSize/=2;
         }
        }
        Text{
            id:acttext
            anchors.top: maintext.bottom
            anchors.right: parent.right
            height: parent.height/6
            width: parent.width/5
            horizontalAlignment: Text.AlignHCenter
            text:bc.act
            font{
                pixelSize: subtext.height
            }
        }

        MouseArea{
            id: ms
            anchors.bottom: parent.bottom
            width: parent.width
            height: parent.height/2
            onPressed: swipe.touchStart(ms.mouseX,ms.mouseY);
            onReleased: swipe.touchEnd(ms.mouseX,ms.mouseY);
        Rectangle{
            id: rect0
            anchors.bottom: parent.bottom
            anchors.left: parent.left
            height:parent.height
            width:parent.width/2
            border.width: 2
            border.color: "black"

            Text{
                anchors.centerIn : parent
                font {
                    pixelSize: parent.height
                }
                text: "0"
            }
  }
        Rectangle{
            id: rect1
            anchors.bottom: parent.bottom
            anchors.right: parent.right
            height:parent.height
            width:parent.width/2
            border.width: 2
            border.color: "black"
            Text{
                anchors.centerIn:  parent
                font {
                    pixelSize: parent.height
                }
                text: "1"
            }
        }
     }
    BiCalc{
        id : bc
        onSenddigit: {
            var news=bc.current.toString(2);
            maintext.text=news;
            if(maintext.contentHeight>maintext.height)
                maintext.font.pixelSize/=2;
        }
        onActChanged:{
            acttext.text=bc.act;
        }
    }
    SwipeArea{
        id: swipe
        sizeX: ms.width
        sizeY: ms.height
        property string pos: "+-*/^"
        onSwipeUp: {
            if(subtext.text!=""){
            bc.recdigit(parseInt(subtext.text,"2"));
            subtext.text=""
            subtext.font.pixelSize=subtext.height-10;
        }
        }
        onSwipeDown:{
            bc.current=0
            maintext.text="0";
            maintext.font.pixelSize=maintext.height-10;
            subtext.text="";
            subtext.font.pixelSize=subtext.height-10;
            maintext.step=1
}
        onSwipeLeft:{
            var ind=swipe.pos.indexOf(bc.act);
            if(ind==0)
                ind=4
            else
                ind-=1;
            bc.act=swipe.pos[ind];
        }
        onSwipeRight:{
            var ind=swipe.pos.indexOf(bc.act);
            if(ind==swipe.pos.length-1)
                ind=0;
            else
                ind+=1;
            bc.act=swipe.pos[ind];
        }
        onClicked0: {
                subtext.text="0"+subtext.text;

        }
            onClicked1: {
                    subtext.text="1"+subtext.text
            }
}
}
