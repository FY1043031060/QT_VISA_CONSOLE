#ifndef MODULEMAPPING_H
#define MODULEMAPPING_H

#include <QObject>

class ModuleMapping : public QObject
{
	Q_OBJECT

public:
	ModuleMapping(QObject *parent);
	~ModuleMapping();

private:
	
};

#endif // MODULEMAPPING_H
