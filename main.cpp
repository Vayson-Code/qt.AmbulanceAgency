#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
a.setApplicationName("SmartAbulanceAgency");
    Connection c;
    bool test=c.createconnect();
  MainWindow w;

  QMediaPlayer * player = new QMediaPlayer;
    QVideoWidget * videoWidget = new QVideoWidget( & w);
    player -> setVideoOutput(videoWidget);
    videoWidget -> setGeometry(0, 0, w.width(), w.height());
    player -> setMedia(QMediaContent(QUrl::fromLocalFile("C:/Users/Vayso/OneDrive/Bureau/ProjetCpp/INTRO.mp4")), nullptr);
    player -> play();
    videoWidget -> showFullScreen();

    QObject::connect(player, & QMediaPlayer::stateChanged, & w, [ & ](QMediaPlayer::State state) {
      if (state == QMediaPlayer::StoppedState) {
        player -> stop();
        videoWidget -> hide();
      }
    });


        if(test)
        {
            w.show();


    }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("connection failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }



       /* if (QWindow *window = qobject_cast<QWindow *>(w.root))
            window->show();
        else
            return -1;*/
        return a.exec();
    }
