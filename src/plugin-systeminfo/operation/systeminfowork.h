/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *             Tianlu Shao <shaotianlu@uniontech.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef SYSTEMINFOWORK_H
#define SYSTEMINFOWORK_H

#include <interface/namespace.h>
#include <QObject>
#include <QDBusMessage>

class SystemInfoDBusProxy;
namespace DCC_NAMESPACE{

class SystemInfoModel;
class SystemInfoWork : public QObject
{
    Q_OBJECT
public:
    explicit SystemInfoWork(SystemInfoModel* model, QObject* parent = nullptr);

    void activate();
    void deactivate();

    void loadGrubSettings();

Q_SIGNALS:
    void requestSetAutoHideDCC(const bool visible) const;

public Q_SLOTS:
    void showActivatorDialog();
    void onSetHostname(const QString &hostname);

private:
    void getLicenseState();

private:
    SystemInfoModel *m_model;
    SystemInfoDBusProxy *m_systemInfDBusProxy;
};

}
#endif // SYSTEMINFOWORK_H
