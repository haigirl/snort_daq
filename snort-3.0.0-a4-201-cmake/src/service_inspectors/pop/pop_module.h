//--------------------------------------------------------------------------
// Copyright (C) 2015-2016 Cisco and/or its affiliates. All rights reserved.
//
// This program is free software; you can redistribute it and/or modify it
// under the terms of the GNU General Public License Version 2 as published
// by the Free Software Foundation.  You may not use, modify or distribute
// this program under any other version of the GNU General Public License.
//
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; if not, write to the Free Software Foundation, Inc.,
// 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
//--------------------------------------------------------------------------

// pop_module.h author Bhagyashree Bantwal <bbantwal@cisco.com>

#ifndef POP_MODULE_H
#define POP_MODULE_H

#include "framework/module.h"
#include "framework/bits.h"
#include "main/thread.h"
#include "pop_config.h"
// Interface to the IMAP service inspector

#define GID_POP 142

#define POP_UNKNOWN_CMD            1
#define POP_UNKNOWN_RESP           2
#define POP_B64_DECODING_FAILED    4
#define POP_QP_DECODING_FAILED     5
#define POP_UU_DECODING_FAILED     7

#define POP_NAME "pop"
#define POP_HELP "pop inspection"

struct SnortConfig;

extern THREAD_LOCAL ProfileStats popPerfStats;

class PopModule : public Module
{
public:
    PopModule();
    ~PopModule();

    bool set(const char*, Value&, SnortConfig*) override;
    bool begin(const char*, int, SnortConfig*) override;
    bool end(const char*, int, SnortConfig*) override;

    unsigned get_gid() const override
    { return GID_POP; }

    const RuleMap* get_rules() const override;
    const PegInfo* get_pegs() const override;
    PegCount* get_counts() const override;
    ProfileStats* get_profile() const override;

    POP_PROTO_CONF* get_data();

private:
    POP_PROTO_CONF* config;
};

#endif
