#ifndef DATAVIEW_H
#define DATAVIEW_H

class DataModel;

class DataView
{
public:
    virtual ~DataView() = default;
    DataView();
    DataModel *model() const;
    void setModel(DataModel *model);

private:
    DataModel *mModel;
};

#endif // DATAVIEW_H
