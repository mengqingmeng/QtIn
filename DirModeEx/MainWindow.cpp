#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    createAction();
    createMenu();

    setupModel();
    setupView();

    setWindowTitle(tr("View Example"));
    resize(600,600);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::createAction()
{
    openAct = new QAction(tr("打开"),this);
    connect(openAct,&QAction::triggered,this,[&](){
        QString name = QFileDialog::getOpenFileName(this,tr("打开"),".","histogram files(*.txt)");
        if(!name.isEmpty())
            openFile(name);
    });
}

void MainWindow::createMenu()
{
    fileMenu = new QMenu(tr("文件"),this);
    fileMenu->addAction(openAct);
    menuBar()->addMenu(fileMenu);
}

void MainWindow::setupModel()
{
    // 创建模型
    model = new QStandardItemModel(4,4,this);
    model->setHeaderData(0,Qt::Horizontal,tr("部门"));
    model->setHeaderData(1,Qt::Horizontal,tr("男"));
    model->setHeaderData(2,Qt::Horizontal,tr("女"));
    model->setHeaderData(3,Qt::Horizontal,tr("退休"));
}

void MainWindow::setupView()
{
    // 创建表格视图
    table = new QTableView;
    table->setModel(model); // 视图与数据模型关联

    QItemSelectionModel* selectionModel = new QItemSelectionModel(model);
    table->setSelectionModel(selectionModel);

    connect(selectionModel,SIGNAL(selectionChanged(QItemSelection,QItemSelection)),
            table,SLOT(selectionChanged(QItemSelection,QItemSelection)));

    splitter = new QSplitter;
    splitter->addWidget(table);
    splitter->setOrientation(Qt::Vertical);
    setCentralWidget(splitter);
}

void MainWindow::openFile(QString path)
{
    if(!path.isEmpty()){
        QFile file(path);
        if(file.open(QFile::ReadOnly | QFile::Text)){
            QTextStream stream(&file);
            QString line;

            model->removeRows(0,model->rowCount(QModelIndex()));
            int row = 0;
            do{
                line = stream.readLine();
                if(!line.isEmpty()){
                    model->insertRows(row,1,QModelIndex());
                    QStringList pieces = line.split(",",Qt::SkipEmptyParts);

                    model->setData(model->index(row,0),pieces.value(0));
                    model->setData(model->index(row,1),pieces.value(1));
                    model->setData(model->index(row,2),pieces.value(2));
                    model->setData(model->index(row,3),pieces.value(3));

                    row++;
                }
            }while(!line.isEmpty());

            file.close();
        }
    }

}

