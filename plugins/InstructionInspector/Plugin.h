/*
Copyright (C) 2016 Ruslan Kabatsayev <b7.10110111@gmail.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef INSTRUCTION_INSPECTOR_PLUGIN_H_20160418
#define INSTRUCTION_INSPECTOR_PLUGIN_H_20160418

#include "IPlugin.h"
#include "edb.h"
#include <QDialog>
#include <vector>

class QTreeWidget;
class QPushButton;
class QVBoxLayout;
class QTextBrowser;

namespace InstructionInspector {

class InstructionDialog : public QDialog {
	Q_OBJECT
	
public:
	struct DisassemblyFailure     {};
	struct InstructionReadFailure {};

public:
	explicit InstructionDialog(QWidget *parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());
	~InstructionDialog() override;

private Q_SLOTS:
	void compareDisassemblers();
	
private:
	QTreeWidget *             tree          = nullptr;
	QPushButton *             compareButton = nullptr;
	QVBoxLayout *             vbox          = nullptr;
	QTextBrowser *            disassemblies = nullptr;
	void *                    insn_         = nullptr;
	void *                    disassembler_ = nullptr;
	edb::address_t            address;
	std::vector<std::uint8_t> insnBytes;
};

class Plugin : public QObject, public IPlugin {
	Q_OBJECT
	Q_INTERFACES(IPlugin)
	Q_PLUGIN_METADATA(IID "edb.IPlugin/1.0")
	Q_CLASSINFO("author", "Ruslan Kabatsayev")
	Q_CLASSINFO("email", "b7.10110111@gmail.com")

public:
	explicit Plugin(QObject *parent = nullptr);
	QMenu *menu(QWidget *parent = nullptr) override;
	QList<QAction *> cpu_context_menu() override;

private Q_SLOTS:
	void showDialog() const;

private:
	QAction *menuAction;
};

}

#endif
