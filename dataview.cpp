#include "dataview.h"

DataModel *DataView::model() const
{
    return mModel;
}

void DataView::setModel(DataModel *model)
{
    mModel = model;
}
