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
#include "stdafx.h"

#include "ronet/packets/pkt_itemgained.h"


namespace ronet {

pktItemGained::pktItemGained() : Packet(pktItemGainedID) {
}

pktItemGained::~pktItemGained() {
}

const InventoryItem& pktItemGained::getItem() {
	return item;
}

bool pktItemGained::Decode(ucBuffer& buf) {
	// Sanity Check
	if (!CheckID(buf))
		return(false);

	buf.ignore(2);

	buf >> item.index;
	buf >> item.amount;
	buf >> item.id;
	buf >> item.identified;
	buf >> item.broken;
	buf >> item.upgrade;
	buf.read((unsigned char*)item.cards, 8);
	buf >> item.type_equip;
	buf >> item.type;
	char fail;
	buf >> fail;

	item.expire = 0;
	item.equipped = 0;

	return(true);
}


}
