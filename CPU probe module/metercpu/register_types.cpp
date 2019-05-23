/* register_types.cpp */

#include "register_types.h"
#include "class_db.h"
#include "metercpu.h"

void register_metercpu_types() {

        ClassDB::register_class<MeterCpu>();
}

void unregister_metercpu_types() {
   //nothing to do here
}
