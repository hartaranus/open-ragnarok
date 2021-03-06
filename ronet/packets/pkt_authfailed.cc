/* $Id$ */
/*
    ------------------------------------------------------------------------------------
    LICENSE:
    ------------------------------------------------------------------------------------
    This file is part of The Open Ragnarok Project
    Copyright 2007 - 2009 The Open Ragnarok Team
    For the latest information visit http://www.open-ragnarok.org
    ------------------------------------------------------------------------------------
    This program is free software; you can redistribute it and/or modify it under
    the terms of the GNU Lesser General Public License as published by the Free Software
    Foundation; either version 2 of the License, or (at your option) any later
    version.

    This program is distributed in the hope that it will be useful, but WITHOUT
    ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS
    FOR A PARTICULAR PURPOSE. See the GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License along with
    this program; if not, write to the Free Software Foundation, Inc., 59 Temple
    Place - Suite 330, Boston, MA 02111-1307, USA, or go to
    http://www.gnu.org/copyleft/lesser.txt.
    ------------------------------------------------------------------------------------
	Author: kR105
*/
#include "stdafx.h"

#include "ronet/packets/pkt_authfailed.h"

ronet::pktAuthFailed::pktAuthFailed() : Packet(pktAuthFailedID) {
	errorId = 0;
}

ronet::pktAuthFailed::~pktAuthFailed() {
	// D:
}

void ronet::pktAuthFailed::Dump() {
	ronet::Packet::Dump();
}

bool ronet::pktAuthFailed::Decode(ucBuffer& buf) {
	// Sanity Check
	if (!CheckID(buf))
		return(false);

	if (buf.dataSize() < 3) // Not enough data
		return(false);

	buf.ignore(2);
	buf.peek((unsigned char*)&errorId, 1);

	// When we're done...
	buf.clear();
	return(true);
}

short ronet::pktAuthFailed::getErrorId() const {
	return(errorId);
}
