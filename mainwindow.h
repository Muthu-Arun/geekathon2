#pragma once
#include <QMap>
#include <QMainWindow>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QString>
#include <QVector>
#include <QTextEdit>
#include <QFont>
#include <QDebug>
#include <QLabel>
#include <QPixmap>
#include <QColor>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();
    QTextEdit* inpt = new QTextEdit();
    QString filter;
    QMap<QString, int> filter_map;
    QVector<QString> lines;
    QVector<QString> ingredients;
    QVector<QString> filtered_lines;
//    QMap<QString>
private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

private:
    Ui::MainWindow *ui;
};
struct diet{
    QVector<QString> non_veg = {"chicken","beef","mutton","steak","hamburger"};
    QVector<QString> low_sugar = {"carrots", "onions", "mushrooms", "asparagus", "celery", "broccoli","brown rice", "crackers",
                                  "quinoa", "oats","seafood", "pork", "beef","lentils", "beans", "soybeans"};
    QVector <QString> protein_rich = {"lentils", "beans", "soybeans","butter", "nuts", "seeds","Yogurt","Chia Seeds","cheese","beans","peanut"};
    QVector <QString> low_fat = {"Leafy Greens","Fruits","Beans","Legumes","Sweet Potatoes","Cherry Juice","Brocolli","Cauliflower","Cabbage","Brussels Sprouts","Bok Choy",
               "Turnips","Mushrooms","Garlic","Grains","Fortified Milk"};
    QVector<QString> low_cholestrol = {"Oats","Barley","Wheat Grains","Beans","EggPlant","Okra","Nuts","Vegetable Oils","Apples","Grapes","Citrus Fruits","Soy"};
    QVector <QString> fiber_rich = {"Avocado","Raspberry","Bean","Broccoli","Lentils","Basil Seed","Banana","Almond","Carrots","Pears"};

};
struct linked_recipes{
    QString str;
    int points = 0;
};
