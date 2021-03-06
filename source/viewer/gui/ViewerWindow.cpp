#include "ui_ViewerWindow.h"
#include "ViewerWindow.hpp"

#include "ViewerHandler.hpp"

#include "gui/ViewerWidget.hpp"
#include "ViewerData.hpp"
#include <settings/CommandLineParameters.hpp>

#include <QtCore/QCoreApplication>
#include <QtGui/QtGui>

/*!
 * Constructor.
 */
ViewerWindow::ViewerWindow(SetupType::Enum setupType,
                           TimestampedFrameQueuePtr queuePtr,
                           CoordinatesConversionPtr coordinatesConversion,
                           QWidget *parent) :
    QMainWindow(parent),
    m_ui(new Ui::ViewerWindow)
{
    m_ui->setupUi(this);
//	setWindowIcon(QIcon(":/images/mobots_logo.png"));

    // and the viewer handler
    m_viewerHandler = ViewerHandlerPtr(new ViewerHandler(setupType, queuePtr, coordinatesConversion), &QObject::deleteLater);
    m_viewerHandler->data()->blockSignals(true);
    // make the frame viewer the central widget
    setCentralWidget(m_viewerHandler->widget());
    connect(m_viewerHandler->widget(), &ViewerWidget::mousePosition, [this](PositionPixels imagePosition, PositionMeters worldPosition) {
        statusBar()->showMessage(tr("Image position: %1, world position: %2").arg(imagePosition.toString()).arg(worldPosition.toString()));
    });
    m_viewerHandler->data()->blockSignals(false);

    // connect the window's actions
    connect(m_ui->actionZoomIn, &QAction::triggered, m_viewerHandler->widget(), &ViewerWidget::onZoomIn);
    connect(m_ui->actionZoomOut, &QAction::triggered, m_viewerHandler->widget(), &ViewerWidget::onZoomOut);
    connect(m_ui->actionSaveCurrentView, &QAction::triggered, m_viewerHandler->widget(), &ViewerWidget::saveCurrentFrameToFile);
}

/*!
 * Destructor.
 */
ViewerWindow::~ViewerWindow()
{
    qDebug() << Q_FUNC_INFO << "Destroying the object";
}
