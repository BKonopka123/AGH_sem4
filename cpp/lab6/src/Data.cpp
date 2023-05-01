#include "Data.h"
#include "List.h"

void IntData::addelem(List &a) const {a.insert(*this);}
void StringData::addelem(List &a) const {a.insert(*this);}
void FloatData::addelem(List &a) const {a.insert(*this);}