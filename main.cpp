#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <bc.h>
#include <sl.h>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);
    qmlRegisterType<bc>("BiCalcModule",1,0,"BiCalc");
    qmlRegisterType<sl>("SwipeModule",1,0,"SwipeArea");
    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;
    return app.exec();
}
