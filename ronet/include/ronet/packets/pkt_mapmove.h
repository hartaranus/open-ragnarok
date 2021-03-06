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
*/
#ifndef __RONET_PACKET_MAPMOVE_H
#define __RONET_PACKET_MAPMOVE_H

#include "ronet/packet.h"

namespace ronet {
/**
 * Packet requesting a move action to the map server
 * \ingroup ronet
 */
class RONET_DLLAPI pktMapMove: public Packet {
protected:
	virtual bool PrepareData();
	int pos_x, pos_y;

	/** Uses padding?
	 * Padding is a one-byte-data between the packet id and the data with a value of 0x44
	 */
	bool m_padding;
public:
	/** Creates a default packet */
	pktMapMove();

	/**
	 * Creates a packet with the given position
	 * @param x
	 * @param y
	 * @param padding uses a one-byte padding?
	 * @param type 0 = 4 end bits padding, 1 = 24 end bits padding
	 */
	pktMapMove(int x, int y, bool padding = false, int type = 0);

	bool Decode(ucBuffer & buf);
	void setPos(int x, int y);
};
}

#endif /* __RONET_PACKET_MAPMOVE_H */
