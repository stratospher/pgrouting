/*PGR-GNU*****************************************************************
File: restriction.cpp
Copyright (c) 2017 Celia Virginia Vergara Castillo
Mail: vicky_vergara@hotmail.com
------
This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
GNU General Public License for more details.
You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA 02110-1301 USA.
********************************************************************PGR-GNU*/

#include "dijkstraTRSP/restriction.h"

#include <vector>
#include <memory>
#include <utility>
#include <limits>

Restriction::Restriction(const Restrict_t &r) :
    m_id(r.id),
    m_cost(r.cost) {
        for(auto &it: r.restricted_edges) {
            if (it == -1) break;
            m_restricted_edges.push_back(it);
        }
    }

std::ostream&
operator << (std::ostream &log, const Restriction& r) {
    log << "Restriction---------------\n";
    log << "ID: " << r.id() << "\n Restricion edge sequence: ";
    for (const auto v : r.m_restricted_edges) {
        log << v <<"\t";
    }
    log << "\n";
    log << "Cost: " << r.cost() << "\n";
    return log;
}
