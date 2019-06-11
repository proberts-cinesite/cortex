//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2013, Image Engine Design Inc. All rights reserved.
//
//  Redistribution and use in source and binary forms, with or without
//  modification, are permitted provided that the following conditions are
//  met:
//
//     * Redistributions of source code must retain the above copyright
//       notice, this list of conditions and the following disclaimer.
//
//     * Redistributions in binary form must reproduce the above copyright
//       notice, this list of conditions and the following disclaimer in the
//       documentation and/or other materials provided with the distribution.
//
//     * Neither the name of Image Engine Design nor the names of any
//       other contributors to this software may be used to endorse or
//       promote products derived from this software without specific prior
//       written permission.
//
//  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
//  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
//  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
//  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
//  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
//  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
//  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
//  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
//  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
//  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
//  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//
//////////////////////////////////////////////////////////////////////////

#ifndef IECOREHOUDINI_UTOBJECTPOOLCACHE_H
#define IECOREHOUDINI_UTOBJECTPOOLCACHE_H

#include "IECore/ObjectPool.h"

#include "UT/UT_Cache.h"

namespace IECoreHoudini
{

/// Registers an IECore::ObjectPool with Houdini's Cache Manager.
/// This allows users to manipulate Cortex memory consumption using
/// the standard Houdini UI. The default UT_ObjectPoolCache is created
/// automatically using the default ObjectPool;
class UT_ObjectPoolCache : public UT_Cache
{

	public :

		UT_ObjectPoolCache( const std::string &name, IECore::ObjectPoolPtr objectPool );
		virtual ~UT_ObjectPoolCache();

		virtual const char *utGetCacheName() const;
		virtual int64 utGetCurrentSize() const;
		virtual int64 utReduceCacheSizeBy( int64 amount );
		virtual bool utHasMaxSize() const;
		virtual int64 utGetMaxSize() const;
		virtual void utSetMaxSize( int64 amount );
		virtual bool utHasMinSize() const;

		static UT_ObjectPoolCache *defaultObjectPoolCache();

	private :

		const std::string m_name;
		IECore::ObjectPoolPtr m_pool;

};

} // namespace IECoreHoudini

#endif // IECOREHOUDINI_UTOBJECTPOOLCACHE_H
