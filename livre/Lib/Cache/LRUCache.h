/* Copyright (c) 2011-2014, EPFL/Blue Brain Project
 *                     Ahmet Bilgili <ahmet.bilgili@epfl.ch>
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

#ifndef _LRUCache_h_
#define _LRUCache_h_

#include <livre/core/Cache/Cache.h>
#include <livre/Lib/Cache/LRUCachePolicy.h>

namespace livre
{

/**
 * The LRUCache class, implementation of the \see Cache with Least Recently Used policy to unload nodes. The
 * derived class should implement the abstract method(s) of \see Cache.
 */
class LRUCache : public Cache
{
public:

    /**
     * Sets a list of node ids to be protected from unloading.
     * @param protectUnloadingList The set of node ids.
     */
    void setProtectList( const CacheIdSet& protectUnloadingList );

    /**
     * Clears the list of node ids to be protected.
     */
    void clearProtectList( );

    /**
     * Sets the maximum memory.
     * @param maxMemoryInMBytes Maximum memory in MB.
     */
    void setMaximumMemory( const uint32_t maxMemoryInMBytes );

    /**
     * Sets the clean up ratio.
     * @param cleanUpRatio Once the policy is activated, ( 1.0 - cleanUpRatio ) can be cleaned.
     */
    void setCleanupRatio( float cleanUpRatio );

protected:

     LRUCache( );

private:

    void onLoaded_( const CacheObject &cacheObject );
    LRUCachePolicy cachePolicy_;
};

}

#endif // _LRUCache_h_