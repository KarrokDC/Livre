/* Copyright (c) 2011-2014, EPFL/Blue Brain Project
 *                     Ahmet Bilgili <ahmet.bilgili@epfl.ch>
 *                     Maxim Makhinya <maxmah@gmail.com>
 *
 * This file is part of Livre <https://github.com/BlueBrain/Livre>
 *
 * This library is free software; you can redistribute it and/or modify it under
 * the terms of the GNU Lesser General Public License version 3.0 as published
 * by the Free Software Foundation.
 *
 * This library is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
 * FOR A PARTICULAR PURPOSE.  See the GNU Lesser General Public License for more
 * details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library; if not, write to the Free Software Foundation, Inc.,
 * 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
 */

#ifndef _AppSettings_h_
#define _AppSettings_h_

#include <QtCore/QCoreApplication>

#include <livre/core/lunchboxTypes.h>

namespace livre
{


#define COMPANY_NAME "BlueBrainProject"
#define PRODUCT_NAME "Livre"


/**
 * settings for QSettings initialization, company and product names.
 */

LB_UNUSED static void setCoreSettingsNames( )
{
    QCoreApplication::setOrganizationName( COMPANY_NAME );
    QCoreApplication::setApplicationName( PRODUCT_NAME );
}

}

#endif // _AppSettings_h_
