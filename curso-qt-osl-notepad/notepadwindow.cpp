#include "notepadwindow.h"

NotepadWindow::NotepadWindow(QWidget *parent)
    : QMainWindow(parent)
{
    //Establecemos el tamaño inicial de la ventana
    this->setGeometry(30, 30, 800, 600);

    // Establecemos el título de la ventana
    // La funcion tr traducira el texto de forma automatica a nuestro lenguaje indicado por locale,
    // siempre y cuando tengamos la base de datos de traducciones añadida al proyecto
    this->setWindowTitle(tr("Mi editor de texto"));

    //Inicializamos los menús
    mainMenu_ = new QMenuBar(this);

    mnuArchivo_ = new QMenu(tr("&Archivo"), this);
    mainMenu_->addMenu(mnuArchivo_);

    actArchivoAbrir_ = new QAction(tr("&Abrir"), this);
    actArchivoAbrir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_O));
    actArchivoAbrir_->setIcon(QIcon(":/icons/Open.ico"));
    mnuArchivo_->addAction(actArchivoAbrir_);

    actArchivoGuardar_ = new QAction(tr("&Guardar"), this);
    actArchivoGuardar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_S));
    actArchivoGuardar_->setIcon(QIcon(":/icons/Save.ico"));
    mnuArchivo_->addAction(actArchivoGuardar_);

    actArchivoSalir_ = new QAction(tr("&Salir"), this); // Anadiendo opcion Archivo/Salir
    actArchivoSalir_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_E)); // Anadiendo opcion Archivo/Salir
    actArchivoSalir_->setIcon(QIcon(":/icons/Exit.ico"));
    mnuArchivo_->addAction(actArchivoSalir_); // Anadiendo opcion Archivo/Salir

    mnuEditar_ = new QMenu(tr("&Editar"), this);
    mainMenu_->addMenu(mnuEditar_);

    actEditarCopiar_ = new QAction(tr("&Copiar"), this);
    actEditarCopiar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_C));
    mnuEditar_->addAction(actEditarCopiar_);

    actEditarPegar_ = new QAction(tr("&Pegar"), this);
    actEditarPegar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_V));
    mnuEditar_->addAction(actEditarPegar_);

    actEditarCortar_ = new QAction(tr("&Cortar"), this); // Anadiendo opcion Editar/Cortar
    actEditarCortar_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_X)); // Anadiendo opcion Editar/Cortar
    mnuEditar_->addAction(actEditarCortar_); // Anadiendo opcion Editar/Cortar

    actEditarDeshacer_ = new QAction(tr("&Deshacer"), this); // Anadiendo opcion Editar/Deshacer
    actEditarDeshacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_U)); // Anadiendo opcion Editar/Deshacer
    mnuEditar_->addAction(actEditarDeshacer_); // Anadiendo opcion Editar/Deshacer

    actEditarRehacer_ = new QAction(tr("&Rehacer"), this); // Anadiendo opcion Editar/Rehacer
    actEditarRehacer_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_Y)); // Anadiendo opcion Editar/Rehacer
    mnuEditar_->addAction(actEditarRehacer_); // Anadiendo opcion Editar/Rehacer

    mnuFormato_ = new QMenu(tr("&Formato"), this);
    mainMenu_->addMenu(mnuFormato_);

    actFormatoFuente_ = new QAction(tr("&Fuente"), this);
    mnuFormato_->addAction(actFormatoFuente_);

    mnuAyuda_ = new QMenu(tr("&Ayuda"), this);
    mainMenu_->addMenu(mnuAyuda_);

    actAyudaAcercaDe_ = new QAction(tr("&Acerca De"), this); // Anadiendo opcion Ayuda/AcercaDe
    actAyudaAcercaDe_->setShortcut(QKeySequence(Qt::CTRL + Qt::Key_A)); // Anadiendo opcion Ayuda/AcercaDe
    mnuAyuda_->addAction(actAyudaAcercaDe_); // Anadiendo opcion Ayuda/AcercaDe

    //Agregamos la barra de menú a la ventana
    this->setMenuBar(mainMenu_);

    //Inicializamos el editor de texto
    txtEditor_ = new QPlainTextEdit(this);

    toolbar_ = new QToolBar();
    toolbar_->addAction(actArchivoAbrir_);
    toolbar_->addAction(actArchivoGuardar_);
    toolbar_->addAction(actArchivoSalir_);
    this->addToolBar(toolbar_);

    //Conectamos las acciones de los menús con nuestros slots
    connect(actArchivoAbrir_,   SIGNAL(triggered()), this,          SLOT(alAbrir()));
    connect(actArchivoGuardar_, SIGNAL(triggered()), this,          SLOT(alGuardar()));
    connect(actArchivoSalir_,   SIGNAL(triggered()), this,          SLOT(alSalir())); // Anadiendo opcion Archivo/Salir
    connect(actEditarCopiar_,   SIGNAL(triggered()), txtEditor_,    SLOT(copy()));
    connect(actEditarPegar_,    SIGNAL(triggered()), txtEditor_,    SLOT(paste()));
    connect(actEditarCortar_,   SIGNAL(triggered()), txtEditor_,    SLOT(cut())); // Anadiendo opcion Editar/Cortar
    connect(actEditarDeshacer_, SIGNAL(triggered()), txtEditor_,    SLOT(undo())); // Anadiendo opcion Editar/Deshacer
    connect(actEditarRehacer_,  SIGNAL(triggered()), txtEditor_,    SLOT(undo())); // Anadiendo opcion Editar/Deshacer
    connect(actFormatoFuente_,  SIGNAL(triggered()), this,          SLOT(alFuente()));
    connect(actAyudaAcercaDe_,  SIGNAL(triggered()), this,          SLOT(alAcercaDe())); // Anadiendo opcion Ayuda/AcercaDe


    //Agregamos el editor de texto a la ventana
    this->setCentralWidget(txtEditor_);
}

NotepadWindow::~NotepadWindow()
{
    //Liberamos los recursos
    mainMenu_->deleteLater();
    actArchivoAbrir_->deleteLater();
    actArchivoGuardar_->deleteLater();
    actArchivoSalir_->deleteLater(); // Anadiendo opcion Archivo/Salir
    mnuArchivo_->deleteLater();
    actEditarCopiar_->deleteLater();
    actEditarPegar_->deleteLater();
    actEditarCortar_->deleteLater(); // Anadiendo opcion Editar/Cortar
    actEditarDeshacer_->deleteLater(); // Anadiendo opcion Editar/Deshacer
    actEditarRehacer_->deleteLater(); // Anadiendo opcion Editar/Rehacer
    mnuEditar_->deleteLater();
    actFormatoFuente_->deleteLater();
    mnuFormato_->deleteLater();
    mnuAyuda_->deleteLater();
    actAyudaAcercaDe_->deleteLater();
    toolbar_->deleteLater();
    txtEditor_->deleteLater();
}

void NotepadWindow::alAbrir()
{
    //Mostramos un dialogo de apertura de ficheros y almacenamos la selección (ruta) en una variable
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getOpenFileName(this,
                                                 tr("Abrir archivo de texto plano"),
                                                 "",
                                                 tr("Archivos de texto plano (*.txt)"));
    if (nombreArchivo != "") {
        //Intentamos abrir el archivo
        QFile archivo;
        archivo.setFileName(nombreArchivo);
        if (archivo.open(QFile::ReadOnly)) {
            //Si se pudo abrir el archivo, lo leemos y colocamos su contenido en nuestro editor
            txtEditor_->setPlainText(archivo.readAll());
            //Se cierra el fichero
            archivo.close();
        }
    }
}

void NotepadWindow::alGuardar()
{
    //Mostramos un dialogo de guardado de ficheros y almacenamos la selección (ruta) en una variable
    QString nombreArchivo;
    nombreArchivo = QFileDialog::getSaveFileName(this,
                                                 tr("Guardar archivo de texto plano"),
                                                 "",
                                                 tr("Archivos de texto plano (*.txt)"));
    if (nombreArchivo != "") {
        //Intentamos abrir el archivo
        QFile archivo;
        if (!nombreArchivo.endsWith(".txt"))
            nombreArchivo += ".txt";
        archivo.setFileName(nombreArchivo);
        if (archivo.open(QFile::WriteOnly | QFile::Truncate)) {
            //Si se pudo abrir el archivo, escribimos el contenido del editor
            archivo.write(txtEditor_->toPlainText().toUtf8());
            //Se cierra el fichero
            archivo.close();
        }
    }
}

void NotepadWindow::alFuente()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, txtEditor_->font(), this);
    if (ok) {
        // Si el usuario hizo click en OK, se establece la fuente seleccionada
        txtEditor_->setFont(font);
    }
}

void NotepadWindow::alSalir() // Anadiendo opcion Archivo/Salir
{
    QMessageBox msgBox;
    msgBox.setText("¿Esta seguro de que desea salir?");
    msgBox.setStandardButtons(QMessageBox::Ok | QMessageBox::Cancel);
    msgBox.setDefaultButton(QMessageBox::Ok);
    int ret = msgBox.exec();
    switch (ret) {
       case QMessageBox::Ok:
           close();
           break;
       case QMessageBox::Cancel:
           break;
       default:
           break;
     }

}

void NotepadWindow::alAcercaDe()
{
    QMessageBox q;
    q.setWindowTitle("Acerca De");
    q.setText("Manuel Luis Aznar\n Copyright 2015");
    q.exec();
}
