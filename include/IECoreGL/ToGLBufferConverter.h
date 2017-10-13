//////////////////////////////////////////////////////////////////////////
//
//  Copyright (c) 2012, Image Engine Design Inc. All rights reserved.
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

#ifndef IECOREGL_TOGLBUFFERCONVERTER_H
#define IECOREGL_TOGLBUFFERCONVERTER_H

#include "IECoreGL/Export.h"
#include "IECoreGL/ToGLConverter.h"

namespace IECore
{

IE_CORE_FORWARDDECLARE( Data )

} // namespace IECore

namespace IECoreGL
{

IE_CORE_FORWARDDECLARE( Buffer )

/// Converts IECore::Data objects into IECoreGL::Buffer objects.
/// \ingroup conversionGroup
class IECOREGL_API ToGLBufferConverter : public ToGLConverter
{

	public :

		typedef IECore::Data InputType;
		typedef IECoreGL::Buffer ResultType;

		IE_CORE_DECLARERUNTIMETYPEDEXTENSION( IECoreGL::ToGLBufferConverter, ToGLBufferConverterTypeId, ToGLConverter );

		ToGLBufferConverter( IECore::ConstDataPtr toConvert = nullptr );
		~ToGLBufferConverter() override;

	protected :

		IECore::RunTimeTypedPtr doConversion( IECore::ConstObjectPtr src, IECore::ConstCompoundObjectPtr operands ) const override;

	private :

		static ConverterDescription<ToGLBufferConverter> g_description;

};

IE_CORE_DECLAREPTR( ToGLBufferConverter );

} // namespace IECoreGL

#endif // IECOREGL_TOGLBUFFERCONVERTER_H
