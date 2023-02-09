#include "ModelEx.h"

ModelEx::ModelEx(QObject* parent) :QAbstractTableModel(parent){

    armyMap[1] = "海军";
    armyMap[2] = "空军";

    weaponTypeMap[1] = "A";
    weaponTypeMap[2] = "B";

    populateModel();
}

int ModelEx::rowCount(const QModelIndex &parent) const
{
    return army.size();
}

int ModelEx::columnCount(const QModelIndex &parent) const
{
    return 2;
}

QVariant ModelEx::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()) return QVariant();

    if(role == Qt::DisplayRole){
        switch(index.column()){
            case 0:
                return armyMap[army[index.row()]];
            case 1:
                return weaponTypeMap[weaponType[index.row()]];
            default:
                return QVariant();
        }
    }
    return QVariant();
}

QVariant ModelEx::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role == Qt::DisplayRole && orientation == Qt::Horizontal){
        return header[section];
    }
    return QAbstractItemModel::headerData(section,orientation,role);
}

void ModelEx::populateModel()
{
    header << "军种" << "武器";
    army << 1 << 2 << 2 << 1;
    weaponType << 1 << 1 << 2 << 2;
}
