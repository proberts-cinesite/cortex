# -*- coding: utf-8 -*-
###########################################################################
#
#  Copyright (c) 2008-2011, Image Engine Design Inc. All rights reserved.
#
#  Redistribution and use in source and binary forms, with or without
#  modification, are permitted provided that the following conditions are
#  met:
#
#     * Redistributions of source code must retain the above copyright
#       notice, this list of conditions and the following disclaimer.
#
#     * Redistributions in binary form must reproduce the above copyright
#       notice, this list of conditions and the following disclaimer in the
#       documentation and/or other materials provided with the distribution.
#
#     * Neither the name of Image Engine Design nor the names of any
#       other contributors to this software may be used to endorse or
#       promote products derived from this software without specific prior
#       written permission.
#
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS
#  IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
#  THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
#  PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
#  CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
#  EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
#  PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR
#  PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF
#  LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
#  NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
#  SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
#
##########################################################################

import IECore
import unittest
import six

class UnicodeToStringTest( unittest.TestCase ) :

	@unittest.skipIf( not six.PY2, "Skipping Python 2 test" )
	def test( self ) :

		s = IECore.StringData( u"hello" )
		self.assertEqual( s.value, "hello" )

	@unittest.skipIf( not six.PY2, "Skipping Python 2 test" )
	def testUnencodeable( self ) :

		self.assertRaises( UnicodeEncodeError, IECore.StringData, u"\322" )

	@unittest.skipIf( not six.PY3, "Skipping Python 3 test" )
	def testPython3( self ) :

		# We expect Unicode strings to be UTF8 encoded when
		# entering C++, and to be decoded back on the way out.

		for s in [
			u"hello",
			u"abcdé",
			u"\322",
		] :

			d = IECore.StringData( s )
			self.assertEqual( d.value, s )

if __name__ == "__main__":
	unittest.main()

