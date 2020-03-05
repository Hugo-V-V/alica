#pragma once

#include <essentials/IdentifierConstPtr.h>

#include <tuple>

namespace alica
{
typedef std::tuple<essentials::IdentifierConstPtr, int64_t> stdSyncReady;
struct SyncReady
{
    SyncReady()
            : senderID(nullptr)
            , synchronisationID(0)
    {
    }
    essentials::IdentifierConstPtr senderID;
    int64_t synchronisationID;

    SyncReady(const stdSyncReady& s)
            : senderID(std::get<0>(s))
            , synchronisationID(std::get<1>(s))
    {
    }

    stdSyncReady toStandard() { return std::make_tuple(senderID, synchronisationID); }
};

} /* namespace alica */
