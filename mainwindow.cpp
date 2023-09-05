#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <Q3DBars>
#include <QQuickItem>
int tri=0,tri1=0,r=0;



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    son=new QSound(":/IMG/ES_Multimedia 839 - SFX Producer.wav");
    ui->tableView->setModel(AL.afficher(tri1));
    ui->tableView_2->setModel(AM.afficher(tri));
player = new QMediaPlayer;

ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
ui->quickWidget->show();

auto obj = ui->quickWidget->rootObject();
connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));

emit setCenter(36.630209,10.044162);
//emit addMarker(36.630209,10.044162);

}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::test()

{

  son->play();

}

void MainWindow::dtest()

{

  son->stop();

}


void MainWindow::on_pushButton_13_clicked()
{
    test();
  ui->stackedWidget->setCurrentIndex(0);
  ui->pushButton_13->setStyleSheet("color:#c2272d;");
    ui->pushButton_9->setStyleSheet("color:none;");
}
void MainWindow::on_pushButton_9_clicked()
{
  ui->stackedWidget->setCurrentIndex(1);
  ui->pushButton_13->setStyleSheet("color:none;");
  ui->pushButton_9->setStyleSheet("color:#c2272d;");
}


void MainWindow::on_pushButton_14_clicked()
{
    test();
    if(ui->lineEdit_17->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "ID est requis");
            ui->label_31->setStyleSheet("color: red;");
        }else if(ui->lineEdit_18->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "LOCALISATION est requis");
            ui->label_30->setStyleSheet("color: red;");
        }else if(ui->radioButton->isChecked()==false && ui->radioButton_2->isChecked()==false){
            QMessageBox::warning(this, "Erreur", "STATUS est requis");
            ui->label_29->setStyleSheet("color: red;");
        }else{
    int n=ui->lineEdit_17->text().toInt();
    QString l=ui->lineEdit_18->text();
    int s;
    if(ui->radioButton->isChecked())
    {
      s=1;
    }
    else
        s=0;
    QString c=ui->lineEdit_16->text();
    Alerte A(n,l,s,c);
    bool test=A.ajouter();
    if(test)
    {
        ui->lineEdit_17->clear();
        ui->lineEdit_18->clear();
        ui->lineEdit_16->clear();
        ui->radioButton->setChecked(false);
        ui->radioButton_2->setChecked(false);
        ui->tableView->setModel(AL.afficher(tri1));
        QMessageBox::information(nullptr, QObject::tr("Ajouter"),
                    QObject::tr("Add successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Ajouter"),
                    QObject::tr("ADD failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
    }
}

void MainWindow::on_pushButton_17_clicked()
{
    test();
    if(ui->lineEdit_19->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "ID est requis");
            ui->label_32->setStyleSheet("color: red;");
        }else{
    int n=ui->lineEdit_19->text().toInt();
    bool test=AL.supprimer(n);
    if(test)
    {
        ui->lineEdit_19->clear();
        ui->tableView->setModel(AL.afficher(tri1));
        QMessageBox::information(nullptr, QObject::tr("Supprimer"),
                    QObject::tr("Delete successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
                    QObject::tr("Delete failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
}
}



void MainWindow::on_pushButton_21_clicked()
{
    test();
    if(ui->lineEdit_22->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "ID est requis");
            ui->label_35->setStyleSheet("color: red;");
        }else if(ui->lineEdit_23->text().isEmpty()){
            QMessageBox::warning(this, "Erreur", "LOCALISATION est requis");
            ui->label_36->setStyleSheet("color: red;");
        }else if(ui->radioButton_3->isChecked()==false && ui->radioButton_4->isChecked()==false){
            QMessageBox::warning(this, "Erreur", "STATUS est requis");
            ui->label_34->setStyleSheet("color: red;");
        }else{

    int n=ui->lineEdit_22->text().toInt();
    QString l=ui->lineEdit_23->text();
    int s;
    if(ui->radioButton_3->isChecked())
    {
      s=1;
    }
    else
        s=0;
    QString c=ui->lineEdit_21->text();
    Alerte A(n,l,s,c);
    bool test=A.modifier();
    if(test)
    {
                ui->lineEdit_22->clear();
                ui->lineEdit_23->clear();
                ui->lineEdit_21->clear();
                ui->radioButton_3->setChecked(false);
                ui->radioButton_4->setChecked(false);
        ui->tableView->setModel(AL.afficher(tri1));
        QMessageBox::information(nullptr, QObject::tr("OK"),
                    QObject::tr("update successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

}
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("NOT OK ITS BAD"),
                    QObject::tr("update failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


}
}
}

void MainWindow::on_tableView_doubleClicked(const QModelIndex &index)
{
    test();
    QAbstractItemModel *model = ui->tableView->model();

        int id = model->data(model->index(index.row(), 0)).toInt();
        QString localisation = model->data(model->index(index.row(), 1)).toString();
        int status = model->data(model->index(index.row(), 2)).toInt();
        QString chemain = model->data(model->index(index.row(), 3)).toString();


 ui->lineEdit_19->setText(QString::number(id));
        ui->lineEdit_22->setText(QString::number(id));
        ui->lineEdit_23->setText(localisation);
        if(status==1)
        {
           ui->radioButton_3->setChecked(true);
        }
        else
            ui->radioButton_4->setChecked(true);
       /* QString filePath = QDir::currentPath();
        int i=chemain.indexOf("/Documents/");
        int e=chemain.indexOf(".wav");
           e=chemain.length()-(i+11+e-3);
        chemain=chemain.mid(i+11,e);*/
        ui->lineEdit_21->setText(chemain);
//emit setsound("C:/Users/Vayso/Documents/aziz.wav");
if(chemain!="")
{

    player->setMedia(QUrl("C:/Users/MSI/Documents/"+chemain+".wav"));
    player->setVolume(50);
    player->play();
}
int i=localisation.indexOf(",");
if(i-1>0)
{
    ui->quickWidget->setSource(QUrl(QStringLiteral("qrc:/map.qml")));
    ui->quickWidget->show();

    auto obj = ui->quickWidget->rootObject();
    connect(this, SIGNAL(setCenter(QVariant, QVariant)), obj, SLOT(setCenter(QVariant, QVariant)));
    connect(this, SIGNAL(addMarker(QVariant, QVariant)), obj, SLOT(addMarker(QVariant, QVariant)));
QString lat=localisation.mid(0,i-1);
QString lng=localisation.mid(i+1);
emit setCenter(lat.toFloat(),lng.toFloat());
emit addMarker(lat.toFloat(),lng.toFloat());
}
else
emit addMarker(0,0);
}

void MainWindow::on_AFFICHER_clicked()
{
    test();
    ui->AFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:#c2272d;");
    ui->AJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:none;");
    ui->SUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:none;");
    ui->MODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:none;");
    ui->pushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->pushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:none;");
  ui->stackedWidget_3->setCurrentIndex(5);
}

void MainWindow::on_AJOUTER_clicked()
{
    test();
    ui->AFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:none;");
    ui->AJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:#c2272d;");
    ui->SUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:none;");
    ui->MODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:none;");
    ui->pushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->pushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:none;");
   ui->stackedWidget_3->setCurrentIndex(4);
}

void MainWindow::on_MODIFIER_clicked()
{
    test();
    ui->AFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:none;");
    ui->AJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:none;");
    ui->SUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:none;");
    ui->MODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:#c2272d;");
    ui->pushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->pushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:none;");
      ui->stackedWidget_3->setCurrentIndex(1);
}

void MainWindow::on_SUPPRIMER_clicked()
{
    test();
    ui->AFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:none;");
    ui->AJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:none;");
    ui->SUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:#c2272d;");
    ui->MODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:none;");
    ui->pushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->pushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:none;");
    ui->stackedWidget_3->setCurrentIndex(0);

}

void MainWindow::on_pushButton_7_clicked()
{
    test();

             QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), "*.pdf");
                    if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                    QPrinter printer(QPrinter::PrinterResolution);
                    printer.setOutputFormat(QPrinter::PdfFormat);
                    printer.setPaperSize(QPrinter::A4);
                    printer.setOutputFileName(fileName);

                    QTextDocument doc;
                    QSqlQuery q;
                    q.prepare("SELECT * FROM ALERTE");
                    q.exec();
                       QString pdf="<hr style='color:red;'><br><h1 style='color:red;text-align=center'><center> Liste des Alertes  : </center></h1><br><hr style='color:red;'><br> <center><img src='C:/Users/Vayso/OneDrive/Bureau/ProjetCpp/IMG/LOGO.png' width='200' height='180'></center><br> <table WIDTH=100% border=1 bordercolor=#FF0000> <thead> <tr>  <th>Id Alerte </th> <th>Adresse</th> <th>Status</th> <th>Vocale</th>  <th>id patient</th> </tr></thead><tbody>";

                    while ( q.next()) {

                        pdf= pdf+ " <br> <tr> <td> "+ q.value(0).toString()+"</td> <td>" + q.value(1).toString() +"</td> <td >" +q.value(2).toString() +"</td><td > "+q.value(3).toString() +"</td><td> "+q.value(4).toString() +"</td>";

                    }
                     pdf= pdf+ " <br>";
                    pdf=pdf+"</tbody></table>";
                    doc.setHtml(pdf);
                    doc.setPageSize(printer.pageRect().size());
                    doc.print(&printer);
    }

void MainWindow::on_re_textChanged(const QString &arg1)
{
ui->tableView->setModel(AL.re(arg1,tri));
}

void MainWindow::on_IDR_clicked()
{
    tri=1;
    QString s=ui->re->text();
    ui->tableView->setModel(AL.re(s,tri));

}

void MainWindow::on_STAR_clicked()
{
   tri=2;
   QString s=ui->re->text();
   ui->tableView->setModel(AL.re(s,tri));
}

void MainWindow::on_ADR_clicked()
{
  tri=3;
  QString s=ui->re->text();
  ui->tableView->setModel(AL.re(s,tri));
}

void MainWindow::on_pushButton_16_clicked()
{
    test();
    ui->AFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:none;");
    ui->AJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:none;");
    ui->SUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:none;");
    ui->MODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:none;");
    ui->pushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->pushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:#c2272d;");

int i=0,s=0,n=0,ac=0,sc=0;
           // Assign names to the set of bars used
           QBarSet *set0 = new QBarSet("Nombre d'Alertes");
           QBarSet *set1 = new QBarSet("Done");
           QBarSet *set2 = new QBarSet("Not Done");
           QBarSet *set3 = new QBarSet("Avec Chemain Vocale");
           QBarSet *set4 = new QBarSet("Sans Chemain Vocale");
           // Assign values for each bar
           QSqlQuery q;
           q.prepare("SELECT * FROM ALERTE");
           q.exec();
           while ( q.next()) {
i++;
               if(q.value(2).toInt()==1)
               {s++;}
               else
               {n++;}
               if(q.value(3).toString()!="")
               {ac++;}
               else
               {sc++;}

}
           *set0 << i;
           *set1 << s;
           *set2 << n;
           *set3 << ac;
           *set4 << sc;
           // Add all sets of data to the chart as a whole
           // 1. Bar Chart
           QBarSeries *series = new QBarSeries();

           // 2. Stacked bar chart
           // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
           series->append(set0);
           series->append(set1);
           series->append(set2);
           series->append(set3);
           series->append(set4);

           // Used to define the bar chart to display, title
           // legend,
           QChart *chart = new QChart();

           // Add the chart
           chart->addSeries(series);

           // Set title
           chart->setTitle("Alertes stats");

           // Define starting animation
           // NoAnimation, GridAxisAnimations, SeriesAnimations
           chart->setAnimationOptions(QChart::AllAnimations);

           // Holds the category titles
           QStringList categories;
           categories << "2023";

           // Adds categories to the axes
           QBarCategoryAxis *axis = new QBarCategoryAxis();
           axis->append(categories);
           chart->createDefaultAxes();

           // 1. Bar chart
           chart->setAxisX(axis, series);

           // 2. Stacked Bar chart
            //chart->setAxisY(axis, series);

           // Define where the legend is displayed
           chart->legend()->setVisible(true);
           chart->legend()->setAlignment(Qt::AlignBottom);

           // Used to display the chart
           QChartView *page = new QChartView(chart);
           page->setRenderHint(QPainter::Antialiasing);
           ui->stackedWidget_2->insertWidget(0,page);
            ui->stackedWidget_2->setCurrentIndex(0);
           // Used to change the palette
           QPalette pal = qApp->palette();

           // Change the color around the chart widget and text
           pal.setColor(QPalette::Window, QRgb(0xffffff));
           pal.setColor(QPalette::WindowText, QRgb(0x404044));

           // Apply palette changes to the application
           qApp->setPalette(pal);

 ui->stackedWidget_3->setCurrentIndex(2);

}

void MainWindow::on_pushButton_2_clicked()
{
    if(r==0){
        QString l=ui->lineEdit_16->text();
    audioRecorder = new QAudioRecorder;
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);

    audioRecorder->setEncodingSettings(audioSettings);
if(l!="")
{
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(l));
    ui->pushButton_2->setText("Arrêter");
    ui->pushButton_3->setText("Arrêter");
    audioRecorder->record();
    r=1;
}
else

     QMessageBox::warning(this, "ERROR","Préciser le Nom du fichier audio");

}
    else
    {
        ui->pushButton_2->setText("Enregistrer");
        ui->pushButton_3->setText("Enregistrer");
        audioRecorder->stop();
        r=0;
    }
}

void MainWindow::on_pushButton_3_clicked()
{
    if(r==0){
        QString l=ui->lineEdit_21->text();
    audioRecorder = new QAudioRecorder;
    QAudioEncoderSettings audioSettings;
    audioSettings.setCodec("audio/amr");
    audioSettings.setQuality(QMultimedia::HighQuality);

    audioRecorder->setEncodingSettings(audioSettings);
if(l!=""){
    audioRecorder->setOutputLocation(QUrl::fromLocalFile(l));
    ui->pushButton_3->setText("Arrêter");
    ui->pushButton_2->setText("Arrêter");
    audioRecorder->record();

    r=1;
}
else
    QMessageBox::warning(this, "ERROR","Préciser le Nom du fichier audio");
}
    else
    {
        ui->pushButton_2->setText("Enregistrer");
        ui->pushButton_3->setText("Enregistrer");
        audioRecorder->stop();
        r=0;
    }
}



//
//AMBULANCE
//

void MainWindow::on_AMAFFICHER_clicked()
{

    ui->AMAFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:#c2272d;");
    ui->AMAJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:none;");
    ui->AMSUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:none;");
    ui->AMMODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:none;");
    ui->AMpushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->AMpushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:none;");
  ui->stackedWidget_4->setCurrentIndex(5);
}

void MainWindow::on_AMAJOUTER_clicked()
{

    ui->AMAFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:none;");
    ui->AMAJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:#c2272d;");
    ui->AMSUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:none;");
    ui->AMMODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:none;");
    ui->AMpushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->AMpushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:none;");
   ui->stackedWidget_4->setCurrentIndex(4);
}
void MainWindow::on_AMMODIFIER_clicked()
{

    ui->AMAFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:none;");
    ui->AMAJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:none;");
    ui->AMSUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:none;");
    ui->AMMODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:#c2272d;");
    ui->AMpushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->AMpushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:none;");
      ui->stackedWidget_4->setCurrentIndex(1);
}

void MainWindow::on_AMSUPPRIMER_clicked()
{

    ui->AMAFFICHER->setStyleSheet("border-image:url(:/IMG/VIEW.png);opacity: .6;background-color:none;");
    ui->AMAJOUTER->setStyleSheet("border-image:url(:/IMG/ADD.png);opacity: .6;background-color:none;");
    ui->AMSUPPRIMER->setStyleSheet("border-image:url(:/IMG/DELETE.png);opacity: .6;background-color:#c2272d;");
    ui->AMMODIFIER->setStyleSheet("border-image:url(:/IMG/EDIT.png);opacity: .6;background-color:none;");
    ui->AMpushButton_7->setStyleSheet("border-image:url(:/IMG/PDF.png);opacity: .6;background-color:none;");
    ui->AMpushButton_16->setStyleSheet("border-image:url(:/IMG/STAT.png);opacity: .6;background-color:none;");
    ui->stackedWidget_4->setCurrentIndex(0);
}


void writeToFile(int fc,QString n, QString l,int s,float c,int d) {
    QFile file("data.txt");
    if (file.open(QIODevice::Append  | QIODevice::Text)) {
        QTextStream out(&file);
        QDateTime dateTime = QDateTime::currentDateTime(); // obtenir la date et l'heure actuelles
        QString text = dateTime.toString("yyyy-MM-dd|hh:mm:ss"); // formater la date et l'heure
        if(fc==1)
        out <<text<<" :ajouter :"<<"||matricule:"<<n<<" ||etat:"<<l<<" ||type:"<<s<<" ||killometrage:"<<c<<" ||disponibilite:"<<d<<"\n";
        else
        out <<text<<" :modifier :"<<"||matricule:"<<n<<" ||etat:"<<l<<" ||type:"<<s<<" ||killometrage:"<<c<<" ||disponibilite:"<<d<<"\n";
        file.close();
    }
}

void writeToFile2(QString n) {
    QFile file("data.txt");
    if (file.open(QIODevice::Append  | QIODevice::Text)) {
        QTextStream out(&file);
        QDateTime dateTime = QDateTime::currentDateTime(); // obtenir la date et l'heure actuelles
        QString text = dateTime.toString("yyyy-MM-dd|hh:mm:ss"); // formater la date et l'heure

        out <<text<<" :supprimer :"<<"||matricule:"<<n<<"\n";

        file.close();
    }
}


void writeToFile3(int p) {
    QFile file("data.txt");
    if (file.open(QIODevice::Append  | QIODevice::Text)) {
        QTextStream out(&file);
        QDateTime dateTime = QDateTime::currentDateTime(); // obtenir la date et l'heure actuelles
        QString text = dateTime.toString("yyyy-MM-dd|hh:mm:ss"); // formater la date et l'heure
        if(p==1)
        out <<text<<" :exporter pdf "<<"\n";
        else
        out <<text<<" :exporter excel "<<"\n";
        file.close();
    }
}

void MainWindow::on_AMpushButton_3_clicked()
{
    QFile file("data.txt");
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream in(&file);
            QPlainTextEdit *textEdit = new QPlainTextEdit;
            textEdit->setMinimumSize(800, 400);
            QFont font("Arial", 9); // Définit une police Arial de taille 16
            textEdit->setFont(font);
            while (!in.atEnd()) {
                QString line = in.readLine();
                textEdit->appendPlainText(line);
            }
            file.close();
            textEdit->show(); // afficher l'éditeur de texte
        }
}

void MainWindow::on_pushButton_24_clicked()
{
int fc=1;

    if(ui->MAT->text().isEmpty()){
                QMessageBox::warning(this, "Erreur", "MAT est requis");
                ui->LMAT->setStyleSheet("color: red;");
            }else if(ui->ETAT->text().isEmpty()){
                QMessageBox::warning(this, "Erreur", "ETAT est requis");
                ui->LETAT->setStyleSheet("color: red;");
            }else if(ui->TYPE->text().isEmpty()){
                QMessageBox::warning(this, "Erreur", "TYPE est requis");
                ui->LTYPE->setStyleSheet("color: red;");
            }else if(ui->KILL->text().isEmpty()){
                QMessageBox::warning(this, "Erreur", "KILL est requis");
                ui->LKILL->setStyleSheet("color: red;");
    }else if(ui->DIS->text().isEmpty()){
        QMessageBox::warning(this, "Erreur", "DIS est requis");
        ui->LDIS->setStyleSheet("color: red;");
            }else{
        QString n=ui->MAT->text();
        QString l=ui->ETAT->text();
        int s=ui->TYPE->text().toInt();
        float c=ui->KILL->text().toFloat();
        int d=ui->DIS->text().toInt();;

         writeToFile(fc,n,l,s,c,d);

        ambulance A(n,l,s,c,d);
        bool test=A.ajouter();
        if(test)
        {
           ui->tableView_2->setModel(AM.afficher(tri));
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("Add successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("NO"),
                        QObject::tr("Add failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }


}

}



void MainWindow::on_pushButton_22_clicked()
{

       if(ui->SMAT->text().isEmpty()){
               QMessageBox::warning(this, "Erreur", "MAT est requis");
               ui->LSMAT->setStyleSheet("color: red;");
           }else{
       QString n=ui->SMAT->text();

        writeToFile2(n);

       bool test=AM.supprimer(n);
       if(test)
       {
           ui->tableView_2->setModel(AM.afficher(tri));
           QMessageBox::information(nullptr, QObject::tr("Supprimer"),
                       QObject::tr("Delete successful.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

   }
       else
       {
           QMessageBox::critical(nullptr, QObject::tr("Supprimer"),
                       QObject::tr("Delete failed.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);


   }
   }
}

void MainWindow::on_pushButton_23_clicked()
{
    int fc=2;
    if(ui->MMAT->text().isEmpty()){
                QMessageBox::warning(this, "Erreur", "MAT est requis");
                ui->LMMAT->setStyleSheet("color: red;");
            }else if(ui->METAT->text().isEmpty()){
                QMessageBox::warning(this, "Erreur", "ETAT est requis");
                ui->LMETAT->setStyleSheet("color: red;");
            }else if(ui->MTYPE->text().isEmpty()){
                QMessageBox::warning(this, "Erreur", "TYPE est requis");
                ui->LMTYPE->setStyleSheet("color: red;");
            }else if(ui->MKILL->text().isEmpty()){
                QMessageBox::warning(this, "Erreur", "KILL est requis");
                ui->LMKILL->setStyleSheet("color: red;");
    }else if(ui->MDIS->text().isEmpty()){
        QMessageBox::warning(this, "Erreur", "DIS est requis");
        ui->LMDIS->setStyleSheet("color: red;");
            }else{
        QString n=ui->MMAT->text();
        QString l=ui->METAT->text();
        int s=ui->MTYPE->text().toInt();
        float c=ui->MKILL->text().toFloat();
        int d=ui->MDIS->text().toInt();;

        writeToFile(fc,n,l,s,c,d);

        ambulance A(n,l,s,c,d);
        bool test=A.modifier();
        if(test)
        {
           ui->tableView_2->setModel(AM.afficher(tri));
            QMessageBox::information(nullptr, QObject::tr("OK"),
                        QObject::tr("update successful.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);

    }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("NO"),
                        QObject::tr("update failed.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);


    }


}



}

void MainWindow::on_tableView_2_clicked(const QModelIndex &index)
{
    QAbstractItemModel *model = ui->tableView_2->model();

            QString mat = model->data(model->index(index.row(), 0)).toString();
            QString etat = model->data(model->index(index.row(), 1)).toString();
            int type = model->data(model->index(index.row(), 2)).toInt();
            float kill= model->data(model->index(index.row(), 3)).toFloat();
            int dis = model->data(model->index(index.row(), 4)).toInt();


     ui->SMAT->setText(mat);
            ui->MMAT->setText(mat);
            ui->METAT->setText(etat);
     ui->MTYPE->setText(QString::number(type));
      ui->MKILL->setText(QString::number(kill,'kill',8));
       ui->MDIS->setText(QString::number(dis));


}

void MainWindow::on_rmat_clicked()
{
    tri=1;
        QString s=ui->recherche->text();
        ui->tableView_2->setModel(AM.re(s,tri));
}

void MainWindow::on_rtype_clicked()
{
    tri=2;
        QString s=ui->recherche->text();
        ui->tableView_2->setModel(AM.re(s,tri));
}

void MainWindow::on_rkill_clicked()
{
    tri=3;
        QString s=ui->recherche->text();
        ui->tableView_2->setModel(AM.re(s,tri));
}

void MainWindow::on_recherche_textChanged(const QString &arg1)
{
    ui->tableView_2->setModel(AM.re(arg1,tri));
}

void MainWindow::on_AMpushButton_7_clicked()
{
    QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Export PDF", QString(), ".pdf");
                        if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                        QPrinter printer(QPrinter::PrinterResolution);
                        printer.setOutputFormat(QPrinter::PdfFormat);
                        printer.setPaperSize(QPrinter::A4);
                        printer.setOutputFileName(fileName);

                        QDateTime dateTime = QDateTime::currentDateTime(); // obtenir la date et l'heure actuelles
                        QString text = dateTime.toString("yyyy-MM-dd|hh:mm:ss"); // formater la date et l'heure

                        QTextDocument doc;
                        QSqlQuery q;
                        q.prepare("SELECT * FROM AMBULANCE");
                        q.exec();
                           QString pdf=" "+text+" <hr style='color:red;'><br><h1 style='color:red;text-align=center'> <center> Liste des Amublances  : </center></h1><br><hr style='color:red;'><br> <center><img src='C:/Users/MSI/Desktop/proj/IMG/LOGO.png' width='200' height='180'></center><br> <table WIDTH=100% border=1 bordercolor=#FF0000> <thead> <tr>  <th>Matricule</th> <th>Etat</th> <th>Type</th> <th>KILOMETRAGE</th>  <th>Disponible</th> </tr></thead><tbody>";

                        while ( q.next()) {

                            pdf= pdf+ " <br> <tr> <td> "+ q.value(0).toString()+"</td> <td>" + q.value(1).toString() +"</td> <td >" +q.value(2).toString() +"</td><td > "+q.value(3).toString() +"</td><td> "+q.value(4).toString() +"</td>";

                        }
                        pdf=pdf+"</tbody></table>";
                        doc.setHtml(pdf);
                        doc.setPageSize(printer.pageRect().size());
                        doc.print(&printer);
                        writeToFile3(1);
}

void MainWindow::on_AMpushButton_16_clicked()
{
    int i=0,s=0,n=0,ac=0,sc=0;
               // Assign names to the set of bars used
               QBarSet *set0 = new QBarSet("Nombre d'ambulance");
               QBarSet *set1 = new QBarSet("fonctionelle");
               QBarSet *set2 = new QBarSet("non fonctionelle");
               QBarSet *set3 = new QBarSet("type A");
               QBarSet *set4 = new QBarSet("type B");
               // Assign values for each bar
               QSqlQuery q;
               q.prepare("SELECT * FROM AMBULANCE");
               q.exec();
               while ( q.next()) {
    i++;
                   if(q.value(1).toString()=="Bon")
                   {s++;}
                   else
                   {n++;}
                   if(q.value(2).toInt()==1)
                   {ac++;}
                   else
                   {sc++;}

    }
               *set0 << i;
               *set1 << s;
               *set2 << n;
               *set3 << ac;
               *set4 << sc;
               // Add all sets of data to the chart as a whole
               // 1. Bar Chart
               QBarSeries *series = new QBarSeries();

               // 2. Stacked bar chart
               // QHorizontalStackedBarSeries *series = new QHorizontalStackedBarSeries();
               series->append(set0);
               series->append(set1);
               series->append(set2);
               series->append(set3);
               series->append(set4);

               // Used to define the bar chart to display, title
               // legend,
               QChart *chart = new QChart();

               // Add the chart
               chart->addSeries(series);

               // Set title
               chart->setTitle("ambulance stats");

               // Define starting animation
               // NoAnimation, GridAxisAnimations, SeriesAnimations
               chart->setAnimationOptions(QChart::AllAnimations);

               // Holds the category titles
               QStringList categories;
               categories << "2023";

               // Adds categories to the axes
               QBarCategoryAxis *axis = new QBarCategoryAxis();
               axis->append(categories);
               chart->createDefaultAxes();

               // 1. Bar chart
               chart->setAxisX(axis, series);

               // 2. Stacked Bar chart
                //chart->setAxisY(axis, series);

               // Define where the legend is displayed
               chart->legend()->setVisible(true);
               chart->legend()->setAlignment(Qt::AlignBottom);

               // Used to display the chart
               QChartView *page = new QChartView(chart);
               page->setRenderHint(QPainter::Antialiasing);
               ui->stackedWidget_5->insertWidget(0,page);
                ui->stackedWidget_5->setCurrentIndex(0);
               // Used to change the palette
               QPalette pal = qApp->palette();

               // Change the color around the chart widget and text
               pal.setColor(QPalette::Window, QRgb(0xffffff));
               pal.setColor(QPalette::WindowText, QRgb(0x404044));

               // Apply palette changes to the application
               qApp->setPalette(pal);

     ui->stackedWidget_4->setCurrentIndex(2);
}


void exportTableToExcel(QTableView* tableView)
{
    // Get column headers
    QStringList headers;
    for (int i = 0; i < tableView->model()->columnCount(); ++i) {
        headers.append(tableView->model()->headerData(i, Qt::Horizontal).toString());
    }

    // Create Excel file
    QXlsx::Document xlsx;
    xlsx.write("A1", headers);
    xlsx.write("A1", "Matricule");
    xlsx.write("B1", "Etat");
    xlsx.write("C1", "Type");
    xlsx.write("D1", "Killometrage");
    xlsx.write("E1", "disponibilite");

    // Write table data to Excel file
    for (int row = 0; row < tableView->model()->rowCount(); ++row) {
        for (int col = 0; col < tableView->model()->columnCount(); ++col) {
            QVariant data = tableView->model()->data(tableView->model()->index(row, col));
            xlsx.write(row + 2, col + 1, data);
        }
    }

    // Prompt user to choose file name and location
    QString fileName = QFileDialog::getSaveFileName(tableView, "Save As", "", "Excel Files (*.xlsx)");
    if (!fileName.isEmpty()) {
        xlsx.saveAs(fileName);
    }
     writeToFile3(2);
}


void MainWindow::on_AMpushButton_2_clicked()
{
     exportTableToExcel(ui->tableView_2);
}

