#pragma once

#include <QMainWindow>
#include <QWidget>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QDialog>
#include <QtWidgets/QStyleFactory>
#include <QLineEdit>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QFontDatabase>
#include <QSystemTrayIcon>

#include "ui_mainwindow.h"
#include "SqlDatabase.h"
#include "bass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    MainWindow(const QString &name, QWidget *parent = nullptr);
    static void setSettings();
    ~MainWindow();
private:
    Ui::MainWindow *ui;
    QSystemTrayIcon *m_icon;
    QString m_login;
};
