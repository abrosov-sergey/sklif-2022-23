#ifndef SKLYPH_PENTOOLMOUSEHANDLER_H
#define SKLYPH_PENTOOLMOUSEHANDLER_H

#include "AbstractToolMouseHandler.h"

#include <QMouseEvent>

namespace sklyph {
namespace valt {

class DicomGriddedViewWidget;

enum class PenToolMode {
    MarkInfection = 0,
    MarkTotalVolume
};

class PenToolMouseHandler: public AbstractToolMouseHandler
{
    Q_OBJECT
public:
    explicit PenToolMouseHandler();
    ~PenToolMouseHandler() override = default;

    void processMouseEvent(QMouseEvent* event) override;

    void setDicomView(DicomViewWidget* view) override;

    void reset() override;

    void setMode(PenToolMode mode);

private: // methods
    void processMousePressEvent(QMouseEvent* event);
    void processMouseMoveEvent(QMouseEvent* event);

    GcellState getPenStateByMouseButtons(bool isLmbPressed, bool isRmbPressed) const;

private: // fields
    DicomGriddedViewWidget* griddedView_; /// Указатель на тот же view, только приведённый к типу Gridded

    PenToolMode mode_;

    QPoint lastRegisteredGridCell_;
};

} // namespace valt
} // namespace sklyph

#endif // SKLYPH_PENTOOLMOUSEHANDLER_H
