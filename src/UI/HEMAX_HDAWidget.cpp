#include "HEMAX_HDAWidget.h"

#include "moc_HEMAX_HDAWidget.cpp"

#if defined(HEMAX_VERSION_2018) || defined(HEMAX_VERSION_2019)
#include <QtWidgets\qapplication.h>
#include <QtWidgets\qfiledialog.h>
#include <QtWidgets\qmenu.h>
#include <QtGui\qclipboard.h>
#endif

#ifdef HEMAX_VERSION_2017
#include <QtGui\qapplication.h>
#include <QtGui\qfiledialog.h>
#include <QtGui\qmenu.h>
#include <QtGui\qclipboard.h>
#endif

HEMAX_HDAWidget::HEMAX_HDAWidget()
    : HEMAX_HDAWidget("Loaded Houdini Digital Assets")
{
}

HEMAX_HDAWidget::HEMAX_HDAWidget(std::string AssetsBoxTitle)
{
    MainLayout = new QVBoxLayout;

    MainBox = new QWidget(this);
    MainBoxLayout = new QVBoxLayout;

    AssetLoadOptionsBox = new QGroupBox;
    AssetLoadOptionsBoxLayout = new QGridLayout;
    AssetLoadOptionsPathLabel = new QLabel("Asset Path:");
    AssetLoadOptionsPath = new QLineEdit;
    AssetLoadOptionsPathBrowse = new QPushButton("...");
    AssetLoadButton = new QPushButton("Load Asset");

    LoadedAssetsBox = new QGroupBox(AssetsBoxTitle.c_str());
    LoadedAssetsBoxLayout = new QVBoxLayout;

    LoadedAssetsList = new QListWidget;
    LoadedAssetsList->setContextMenuPolicy(Qt::CustomContextMenu);
    LoadSelectedAssetButton = new QPushButton("Create Object");
    LoadSelectedAssetButton->setMinimumHeight(HEMAX_HDAWIDGET_CREATE_BUTTONS_MIN_HEIGHT);
    CreateModifiersButton = new QPushButton("Create Modifier HDA On Selected Objects");
    CreateModifiersButton->setMinimumHeight(HEMAX_HDAWIDGET_CREATE_BUTTONS_MIN_HEIGHT);

    MainLayout->setAlignment(Qt::AlignTop);
    MainBoxLayout->setAlignment(Qt::AlignTop);
    LoadedAssetsBox->setAlignment(Qt::AlignTop);
    LoadedAssetsBoxLayout->setAlignment(Qt::AlignTop);

    AssetLoadOptionsBoxLayout->addWidget(AssetLoadOptionsPathLabel, 0, 0);
    AssetLoadOptionsBoxLayout->addWidget(AssetLoadOptionsPath, 1, 0);
    AssetLoadOptionsBoxLayout->addWidget(AssetLoadOptionsPathBrowse, 1, 1);
    AssetLoadOptionsBoxLayout->addWidget(AssetLoadButton, 2, 1);

    AssetLoadOptionsBox->setLayout(AssetLoadOptionsBoxLayout);

    LoadedAssetsBoxLayout->addWidget(LoadedAssetsList);
    LoadedAssetsBoxLayout->addWidget(LoadSelectedAssetButton);
    LoadedAssetsBoxLayout->addWidget(CreateModifiersButton);

    LoadSelectedAssetButton->setDisabled(true);
    CreateModifiersButton->setDisabled(true);
    LoadedAssetsList->setMaximumHeight(HEMAX_HDAWIDGET_MAX_LIST_HEIGHT);

    LoadedAssetsBox->setLayout(LoadedAssetsBoxLayout);

    MainBoxLayout->addWidget(AssetLoadOptionsBox);
    MainBoxLayout->addWidget(LoadedAssetsBox);

    MainBox->setLayout(MainBoxLayout);
    MainLayout->addWidget(MainBox);

    this->setLayout(MainLayout);

    QObject::connect(AssetLoadOptionsPathBrowse, SIGNAL(clicked()), this, SLOT(SlotAssetLoadOptionsPathBrowse()));
    QObject::connect(LoadedAssetsList, SIGNAL(itemClicked(QListWidgetItem*)), this, SLOT(SlotLoadedAssetItemClicked(QListWidgetItem*)));
    QObject::connect(LoadedAssetsList, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(SlotShowAssetContextMenu(QPoint)));
}

HEMAX_HDAWidget::~HEMAX_HDAWidget()
{
    delete CreateModifiersButton;
    delete LoadSelectedAssetButton;

    delete LoadedAssetsList;
    delete LoadedAssetsBoxLayout;
    delete LoadedAssetsBox;

    delete AssetLoadButton;
    delete AssetLoadOptionsPathBrowse;
    delete AssetLoadOptionsPath;
    delete AssetLoadOptionsPathLabel;
    delete AssetLoadOptionsBoxLayout;
    delete AssetLoadOptionsBox;

    delete MainBoxLayout;
    delete MainBox;

    delete MainLayout;
}

void
HEMAX_HDAWidget::SlotAssetLoadOptionsPathBrowse()
{
    AssetLoadOptionsPath->setText(QFileDialog::getOpenFileName());
}

std::string
HEMAX_HDAWidget::GetCurrentAssetLoadPath()
{
    return AssetLoadOptionsPath->text().toStdString();
}

std::string
HEMAX_HDAWidget::GetSelectedAssetPath()
{
    return SelectedAssetPath.toStdString();
}

void
HEMAX_HDAWidget::SlotLoadedAssetItemClicked(QListWidgetItem* Item)
{
    LoadSelectedAssetButton->setDisabled(false);
    CreateModifiersButton->setDisabled(false);

    SelectedAssetPath = Item->toolTip();
}

void
HEMAX_HDAWidget::UpdateLoadedAssetList(std::vector<std::string>* Paths)
{
    LoadedAssetsList->clear();
    LoadSelectedAssetButton->setDisabled(true);
    CreateModifiersButton->setDisabled(true);

    for (int i = 0; i < Paths->size(); ++i)
    {
        QFileInfo HDAFile(Paths->at(i).c_str());

        LoadedAssetsList->addItem(HDAFile.fileName());
        LoadedAssetsList->item(i)->setToolTip(Paths->at(i).c_str());
    }

    LoadedAssetsList->sortItems();
}

void
HEMAX_HDAWidget::SetAssetLoadWidgetEnabled(bool Enabled)
{
    AssetLoadOptionsBox->setEnabled(Enabled);
    AssetLoadOptionsBox->setVisible(Enabled);
}

void
HEMAX_HDAWidget::SlotShowAssetContextMenu(QPoint Position)
{
    QPoint MenuSpawn = LoadedAssetsList->mapToGlobal(Position);
    QListWidgetItem* Item = LoadedAssetsList->itemAt(Position);
    QString FullAssetPath = Item->toolTip();
    CurrentContextMenuSelection = FullAssetPath;

    QMenu AssetMenu;
    AssetMenu.addAction("Remove Asset", this, SLOT(SlotRemoveAssetClicked()));
	AssetMenu.addAction("Copy Asset Path", this, SLOT(SlotCopyAssetPathClicked()));
    AssetMenu.exec(MenuSpawn);
}

void
HEMAX_HDAWidget::SlotRemoveAssetClicked()
{
    emit SignalRemoveAssetClicked(CurrentContextMenuSelection);
}

void
HEMAX_HDAWidget::SlotCopyAssetPathClicked()
{
	QClipboard* Clipboard = QApplication::clipboard();
	Clipboard->setText(CurrentContextMenuSelection);
}