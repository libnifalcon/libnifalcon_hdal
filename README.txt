========================================
libnifalcon - HDAL Compatibility Library
========================================

by Kyle Machulis <kyle@nonpolynomial.com>
Nonpolynomial Labs - http://www.nonpolynomial.com

Original HDAL Code by Novint
http://home.novint.com

===========
Description
===========

libnifalcon_hdal is a compatability to use libnifalcon to compile software for different plaforms using Novint's HDAL SDK. Many programs and libraries have already been written to use the HDAL (CHAI 3D, H3DAPI, etc...), and with this library, they should work with the Novint Falcon for all platforms, not just windows. Using libnifalcon_hdal in any of these projects will hopefully require a minimal amount of additions to the build system and (hopefully) no changes to code.

Since the library will be dependant on keeping up with Novint's version releases as well as staying in step with the libnifalcon development path, I've made it a seperate library altogether.

=========
Licensing
=========

Due to the fact that this library uses code from Novint's SDK, it is covered under the Novint Non-Commercial License (contained in licenses/LICENSE_NOVINT.txt). So no making money. libnifalcon itself is BSD licensed.

=========================
NovInt Falcon Information
=========================

More information about the NovInt Falcon can be found at 

http://home.novint.com

The SDK information is available at

http://home.novint.com/products/sdk.php

Technical information, including protocol and hardware information, is available at

http://wiki.libnifalcon.sourceforge.net

====================
Library Requirements
====================

-----
cmake
-----
http://www.cmake.org

-----------
libnifalcon
-----------

http://libnifalcon.sourceforge.net

==================
Platform Specifics
==================

-------
Windows
-------

- If you're running this on windows... Why? You have HDAL access already. Stop being silly and just use that. :)
