
/* Copyright (c) 2011-2017, Maxim Makhinya <maxmah@gmail.com>
 *                          David Steiner  <steiner@ifi.uzh.ch>
 *                          Ahmet Bilgili  <ahmet.bilgili@epfl.ch>
 *                          Stefan.Eilemann@epfl.ch
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

#include <co/dataIStream.h>
#include <co/dataOStream.h>
#include <livre/eq/settings/RenderSettings.h>

namespace livre
{
RenderSettings::RenderSettings()
{
}

void RenderSettings::resetTransferFunction()
{
    setTransferFunction(TransferFunction1D());
}

void RenderSettings::setTransferFunction(const TransferFunction1D& tf)
{
    _transferFunction = tf;
}

void RenderSettings::setClipPlanes(const ClipPlanesDist& clipPlanes)
{
    _clipPlanes = clipPlanes;
}
}
