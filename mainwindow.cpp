/* ⴰⵣⵓⵍ ⴼⵍⴰⴽ
 * ⴰⴷⵓⵔ ⵜⵓⵜ ⴰⵢⵉ ⵜⵙⵉⴼⴷ ⵉⵅⴼⴰⵡⵏ ⵏⴽ ⴼ ⴰⵙⵏⴰⵙ ⴰⴷ
 * ⴼⴰⵉⵙⴻⴱⴽ ⵉⵏⵓ: https://www.facebook.com/Akal.Awal.Afgan.Yaz
 * 25/26/2016
 * ⵜⴰⵏⵎⵉⵔⵜ
*/
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlQuery>
#include <QTableWidgetItem>
#include <QString>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    Columns="tifinagh,tifinagh_in_arabic,arabic,arabic_meaning";
    TableColumns[0]="تيفيناغ, تيفيناغ بحروف عربية, العربية, المعنى";
    TableColumns[1]="ⵜⵉⴼⵉⵏⴰⵖ, ⵜⵉⴼⵉⵏⴰⵖ ⵙ ⵜⴰⵄⵔⴰⴱⵜ, ⵜⴰⵄⵔⴰⴱⵜ, ⴰⵎⵎⴰⴽ";
    db=QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("Dictionary.db");
    setWindowTitle("ⴰⵎⴰⵡⴰⵍ ⵎⵄⵜⵓⴱ ⵍⵓⵏⴰⵙ || قاموس معتوب لوناس");
}

MainWindow::~MainWindow()
{
    delete ui;
}
QString Enjection(QString Text);
QString Validation(QString Text);
struct Language{
    QString Tamazight="Tifihagh";
    QString Arabic="Seriani";
    QString None="None";
};
void MainWindow::on_Searchbtn_clicked()
{
    QString Tables[4];
    QString word=Enjection(ui->SearchSpace->text());
    QString options[]={"Arabic","Tamazight"};
    ui->Result->setColumnCount(TableColumns[0].split(',').count());

    if(Validation(word)==options[0]){
        Tables[0]="_arabic";
        Tables[1]="_tifinagh_in_arabic";
        Tables[2]="arabic";
        Tables[3]="tifinagh_in_arabic";
        for(int i=0;i<TableColumns[0].split(',').count();i++)
            ui->Result->setHorizontalHeaderItem(i,new QTableWidgetItem(TableColumns[0].split(',')[i]));
    }else if(Validation(word)==options[1]){
        Tables[0]="tifinagh";
        for(int i=0;i<TableColumns[1].split(',').count();i++)
            ui->Result->setHorizontalHeaderItem(i,new QTableWidgetItem(TableColumns[1].split(',')[i]));
    }
    else
        return;
    QString QueryString="select "+Columns+" from words where ";
    for (int i=0;i<4;i++) {
        if(i==0)
            QueryString+=Tables[i]+" like '%"+word+"%'";
        else
            if(Tables[i].length()>0)
            QueryString+=" or "+Tables[i]+" like '%"+word+"%'";
    }
    while(ui->Result->rowCount()>0){
    for(int i=0 ; i < ui->Result->rowCount(); i++)
        ui->Result->removeRow(i);
    }
   db.open();
    QSqlQuery query;
    if(query.exec(QueryString)){
        int row=0;
        while(query.next()){
            ui->Result->insertRow(row);
            for(int column=0;column<9;column++){
                QTableWidgetItem *item=new QTableWidgetItem(query.value(column).toString());
                ui->Result->setItem(row,column,item);
            }
            row++;
        }
    }
    db.close();
}
QString Enjection(QString Text){
    QString _Text="";
    foreach(QChar character,Text){
        if(character=='\'')
            _Text+="\\";
        else
            _Text+=character;
    }
    return _Text;
}
void MainWindow::on_SearchSpace_textChanged()
{
    if(ui->SearchSpace->text().length()>0)
        ui->Searchbtn->setEnabled(true);
    else
        ui->Searchbtn->setEnabled(false);
}

QString Validation(QString Text){
    QString tifinagh_chars="ⴰⵣⴻⵔⵜⵢⵓⵉⵄⵃⵇⵙⴷⴼⴳⵀⵊⴽⵍⵎⵡⵅⵛⵖⴱⵏ";
    foreach(QChar item,Text){
        foreach(QChar _item,tifinagh_chars){
            if(item==_item)
                return "Tamazight";
        }
    }
    QString Arabic_chars="ضصثقفغعهخحجدذشسيبلاتنمكطئءؤرلىةوزظ";
    foreach(QChar item,Text){
        foreach(QChar _item,Arabic_chars){
            if(item==_item)
                return "Arabic";
        }
    }
    return "None";
}
