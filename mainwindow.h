#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "ambulance.h"
#include <QPrinter>
#include <QtPrintSupport>
#include <QSound>
#include <QMainWindow>
#include <QMessageBox>
#include <QApplication>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QMediaContent>
#include <QTimer>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QMediaPlayer>
#include <QtCore>
#include <QPdfWriter>
#include <QPainter>
#include "connection.h"
#include "alerte.h"
#include <QtDataVisualization>
#include <Q3DBars>
#include <QtWidgets/QMainWindow>
#include <QAudioRecorder>
#include <QQmlApplicationEngine>
#include <QGuiApplication>
#include <QWindow>
#include <QQmlContext>
#include <QStandardPaths>
#include <QDir>


#include "xlsxdocument.h"
#include "xlsxchartsheet.h"
#include "xlsxcellrange.h"
#include "xlsxchart.h"
#include "xlsxrichstring.h"
#include "xlsxworkbook.h"
using namespace QXlsx;

#include <QFile>
#include <QTextStream>
#include <QDateTime>

// Widget used to display charts
#include <QtCharts/QChartView>

// Used to draw bars representing data provided
// grouped into categories
#include <QtCharts/QBarSeries>

// Represents 1 set of bars in a bar chart
#include <QtCharts/QBarSet>

// Displays the color used to represent each
// QBarSet
#include <QtCharts/QLegend>

// Adds categories to the charts axes
#include <QtCharts/QBarCategoryAxis>

// Used to create stacked bar charts
#include <QtCharts/QHorizontalStackedBarSeries>

// Used to create a line chart
#include <QtCharts/QLineSeries>

// Used to change names on axis
#include <QtCharts/QCategoryAxis>

// Used to make Pie Charts
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QStringBuilder>
// Define the scope for your variables and functions
QT_CHARTS_USE_NAMESPACE
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void test();
    void dtest();
    //QQmlApplicationEngine engine;
   // QObject* root;
private slots:

    void on_AMAFFICHER_clicked();

    void on_AMAJOUTER_clicked();

    void on_AMMODIFIER_clicked();

    void on_AMSUPPRIMER_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_tableView_2_clicked(const QModelIndex &index);

    void on_rmat_clicked();

    void on_rtype_clicked();

    void on_rkill_clicked();

    void on_recherche_textChanged(const QString &arg1);

    void on_AMpushButton_7_clicked();

    void on_AMpushButton_16_clicked();

    void on_AMpushButton_2_clicked();

    void on_AMpushButton_3_clicked();


//
//
//
    void on_pushButton_13_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_21_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void on_AFFICHER_clicked();

    void on_AJOUTER_clicked();

    void on_MODIFIER_clicked();

    void on_SUPPRIMER_clicked();

    void on_pushButton_7_clicked();

    void on_re_textChanged(const QString &arg1);

    void on_IDR_clicked();

    void on_STAR_clicked();

    void on_ADR_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();


private:
    Ui::MainWindow *ui;
      QSound *son;
      Alerte AL;
      QAudioRecorder * audioRecorder;
      QMediaPlayer *player;
       ambulance AM;

signals:
    void setCenter(QVariant, QVariant);
    void addMarker(QVariant, QVariant);
};
#endif // MAINWINDOW_H
