#include "mainwindow.h"
#include "ui_mainwindow.h"

class match{
public:
    QVector<QString> m_filter(QVector<QString> vect,int i){
        diet d;
        int points = 0;
        QString str;
        QVector<QString> local;

        switch(i){
        case 0:
            return vect;
            break;
        case 1:
            for(QString j:vect){
                str = j.toLower();
                for(QString k:d.low_sugar){
                    if(str.contains(k.toLower())){
                    points++;
                    }
                }
                if(points >= d.low_sugar.size()/3){
                    local.append(j);
                }

            }

            return vect;
            break;
        case 2:
            for(QString j:vect){
                str = j.toLower();
                for(QString k:d.low_fat){
                    if(str.contains(k.toLower())){
                    points++;
                }
                }
                if(points >= d.low_fat.size()/3){
                    local.append(j);
                }

            }

            return vect;
            break;
        case 3:
            for(QString j:vect){
                str = j.toLower();
                for(QString k:d.low_cholestrol){
                    if(str.contains(k.toLower())){
                    points++;
                }
                }
                if(points >= d.low_cholestrol.size()/3){
                    local.append(j);
                }

            }

            return vect;
            break;
        case 4:
            for(QString j:vect){
                str = j.toLower();
                for(QString k:d.protein_rich){
                    if(str.contains(k.toLower())){
                    points++;
                }
                }
                if(points >= d.protein_rich.size()/3){
                    local.append(j);
                }

            }

            return vect;
            break;
        case 5:
            for(QString j:vect){
                str = j.toLower();
                for(QString k:d.fiber_rich){
                    if(str.contains(k.toLower()));
                    points++;
                }
                if(points >= d.fiber_rich.size()/2){
                    local.append(j);
                }

            }

            return vect;
            break;
        default:
            break;
        }



    }
};




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    filter_map["None"] = 0;
    filter_map["Low Sugar"] = 1;
    filter_map["Low Fat"] = 2;
    filter_map["Low Cholestrol"] = 3;
    filter_map["Protein Rich"] = 4;
    filter_map["Fiber Rich"] = 5;
    QLabel* lbl = new QLabel();
    ui->stackedWidget->addWidget(lbl);
    lbl->setPixmap(QPixmap(":/imgs/woman-6754248_640.jpg"));

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
//    ui->textEdit->clear();
    diet* dt = new diet;
    match m;
    bool state = false;
    filter = ui->comboBox->currentText();
    QFile file(":/res/textfile.txt");
    if(file.open(QFile::ReadOnly | QFile::Text)){
        QTextStream in(&file);
        while(!in.atEnd()){
            QString txt = in.readLine();
            for(QString i:ingredients){
                state = txt.contains(i);
                for(QString y:dt->non_veg){
                    if(txt.contains(y)){
                    state = false;
                    }
                }
                if(state){
                    lines.append(txt);
                }
//                    ui->label_4->setText("in loop");
                }
            }
        }

        QVector<QString> new_vect = m.m_filter(lines,filter_map[filter]);
        for(QString y:lines){
            QTextEdit* ed = new QTextEdit(ui->stackedWidget);
            ed->setTextColor(QColor(0, 255, 0,127));
            ed->setText(y);
//            ed->setTextBackgroundColor(QColor("green"));
            ed->setFont(QFont("Times",16));

            ui->stackedWidget->addWidget(ed);
        }
        ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);



    }

void MainWindow::on_pushButton_2_clicked(){
    if(ui->textEdit->toPlainText() != ""){
    ingredients.append(ui->textEdit->toPlainText());
    ui->textEdit->clear();

    }
}

void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex() -1);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(ui->stackedWidget->currentIndex()+1);
}

