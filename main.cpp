#include <QApplication>
#include <QDebug>
#include <QTime>
#include <ResourceView.h>
int main(int argc, char *argv[])
{
#if 0

    ViStatus  status = 0;
    ViSession defaultRM = 0, instr = 0;
    ViSession session[] = { 0 };
    ViUInt32 retCnt = 0;
    ViChar descriptor[256];
    std::list<std::string> listSession;
    /* Open Default RM */
    status = viOpenDefaultRM(&defaultRM);
    if(status < VI_SUCCESS)
    {
        /* Error Initializing VISA...exiting */
        return -1;

    }
    status = viFindRsrc(defaultRM, (ViString)"visa://NT-G6000/?*", &session[0], &retCnt, descriptor);



    for(int index = 0; index < retCnt - 1; index++)
    {
        status = viFindNext(session[index], descriptor);
    }
    if(status < VI_SUCCESS)
    {
        return -1;
    }
    if(retCnt == 0)
    {
        return -1;
    }
    /* Access other resources */
    status = viOpen(defaultRM, (ViRsrc)"GPIB::1::INSTR", VI_NULL, VI_NULL, &instr);

    /* Use device and eventually close it. */
    viClose(instr);
    viClose(defaultRM);
#endif
    QApplication a(argc, argv);
    ResourceView rv;
    rv.show();
#if 0
    ResourceManager rm;
    qDebug() << QTime::currentTime().toString();

    qDebug() << "_SIZE_" << rm.getResourcesList().size() << "_string_" <<rm.getResourcesList();
    qDebug() << QTime::currentTime().toString();

    qDebug() << "INF_TYPE " << rm.getResourcesByType(1);
#endif
    return a.exec();
}
