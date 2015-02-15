#ifndef NOTEPADWINDOW_H
#define NOTEPADWINDOW_H

#include <QMainWindow>
//Incluimos librerias necesarias
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QPlainTextEdit>
#include <QFileDialog>
#include <QFile>
#include <QFontDialog>
#include <QClipboard>
#include <QKeySequence>
#include <QMessageBox>
#include <QToolBar>

class NotepadWindow : public QMainWindow
{
    Q_OBJECT

public:
    NotepadWindow(QWidget *parent = 0);
    ~NotepadWindow();

private slots:
    void alAbrir();
    void alGuardar();
    void alFuente();
    void alSalir(); // Anadiendo opcion Archivo/Salir
    void alAcercaDe();

private:
    QMenuBar*       mainMenu_;
    QMenu*          mnuArchivo_;
    QAction*        actArchivoAbrir_;
    QAction*        actArchivoGuardar_;
    QAction*        actArchivoSalir_; // Anadiendo opcion Archivo/Salir
    QMenu*          mnuFormato_;
    QAction*        actFormatoFuente_;
    QMenu*          mnuEditar_;
    QAction*        actEditarCopiar_;
    QAction*        actEditarPegar_;
    QAction*        actEditarCortar_; // Anadiendo opcion Editar/Cortar
    QAction*        actEditarDeshacer_; // Anadiendo opcion Editar/Deshacer
    QAction*        actEditarRehacer_; // Anadiendo opcion Editar/Rehacer
    QPlainTextEdit* txtEditor_;
    QMenu*          mnuAyuda_;
    QAction*        actAyudaAcercaDe_;
    QClipboard*     portapapeles_;
    QToolBar*       toolbar_;

};

#endif // NOTEPADWINDOW_H
