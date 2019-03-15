/*
 * Copyright information and license terms for this software can be
 * found in the file LICENSE that is included with the distribution
 */

/**
 * @author mrk
 * @date 2013.04.02
 */

#include <pv/pvData.h>
#include <pv/timeStamp.h>
#include <pv/standardField.h>
#include <pv/standardPVField.h>

#include <epicsExport.h>
#include <pv/tableRecord.h>

using namespace epics::pvData;
using namespace epics::pvDatabase;
using std::string;
using std::cout;
using std::cerr;
using std::endl;

namespace epics { namespace exampleCPP {namespace table { 

TableRecordPtr TableRecord::create(
    string const & recordName)
{
    FieldCreatePtr fieldCreate = getFieldCreate();
    StandardFieldPtr standardField = getStandardField();
    PVDataCreatePtr pvDataCreate = getPVDataCreate();

    StructureConstPtr  topStructure = fieldCreate->createFieldBuilder()->
            addArray("labels",pvString) ->
            addNestedStructure("value") ->
               addArray("x",pvDouble) ->
               addArray("y",pvDouble) ->
               addArray("z",pvDouble) ->
               addArray("time_index",pvInt) ->
               endNested()->
            add("descriptor",pvString) ->
            add("alarm",standardField->alarm()) ->
            add("timeStamp",standardField->timeStamp()) ->
            add("counter",pvInt) ->
            createStructure();
    PVStructurePtr pvStructure = pvDataCreate->createPVStructure(topStructure);
    TableRecordPtr pvRecord(
        new TableRecord(recordName,pvStructure));
    pvRecord->initPvt();
    return pvRecord;
}

TableRecord::TableRecord(
    string const & recordName,
    PVStructurePtr const & pvStructure)
: PVRecord(recordName,pvStructure)
{
}


void TableRecord::initPvt()
{
    initPVRecord();
}

void TableRecord::process()
{
    PVRecord::process();
}

}}}
