#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include<QString>
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    QSqlDatabase db;
    QString Columns;
    QString TableColumns[2];
private slots:
    void on_Searchbtn_clicked();

    void on_SearchSpace_textChanged();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
