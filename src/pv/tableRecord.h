/*
 * Copyright information and license terms for this software can be
 * found in the file LICENSE that is included with the distribution
 */

/**
 * @author mrk
 * @date 2013.04.02
 */
#ifndef TABLERECORD_H
#define TABLERECORD_H


#include <pv/timeStamp.h>
#include <pv/alarm.h>
#include <pv/pvTimeStamp.h>
#include <pv/pvAlarm.h>
#include <pv/pvDatabase.h>


#include <shareLib.h>


namespace epics { namespace exampleCPP {namespace table { 

class TableRecord;
typedef std::tr1::shared_ptr<TableRecord> TableRecordPtr;

class epicsShareClass TableRecord :
    public epics::pvDatabase::PVRecord
{
public:
    POINTER_DEFINITIONS(TableRecord);
    static TableRecordPtr create(
        std::string const & recordName);
    virtual ~TableRecord() {}
    virtual bool init() {return false;}
    virtual void process();
    
private:
    TableRecord(std::string const & recordName,
        epics::pvData::PVStructurePtr const & pvStructure);
    void initPvt();
};


}}}

#endif  /* TABLERECORD_H */
