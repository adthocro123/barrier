/*
    InputLeap -- mouse and keyboard sharing utility
    Copyright (C) InputLeap contributors
    Copyright (C) 2026 Barrier Next contributors

    This package is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License
    found in the file LICENSE that should have accompanied this file.

    This package is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include "FingerprintAcceptDialog.h"
#include "ui_FingerprintAcceptDialog.h"
#include "net/SecureUtils.h"

#include <QPushButton>

FingerprintAcceptDialog::FingerprintAcceptDialog(QWidget *parent,
                                                 AppRole type,
                                                 const inputleap::FingerprintData& fingerprint_sha1,
                                                 const inputleap::FingerprintData& fingerprint_sha256) :
    QDialog(parent),
    ui_{std::make_unique<Ui::FingerprintAcceptDialog>()}
{
    ui_->setupUi(this);
    ui_->buttonBox->button(QDialogButtonBox::Yes)->setText(tr("Trust and connect"));
    ui_->buttonBox->button(QDialogButtonBox::No)->setText(tr("Cancel"));

    if (type == AppRole::Server) {
        ui_->label_sha1->hide();
        ui_->label_sha1_fingerprint_full->hide();
    } else {
        ui_->label_sha1_fingerprint_full->setText(
                QString::fromStdString(inputleap::format_ssl_fingerprint(fingerprint_sha1.data)));
    }

    ui_->label_sha256_fingerprint_full->setText(
            QString::fromStdString(inputleap::format_ssl_fingerprint_columns(fingerprint_sha256.data)));
    ui_->label_sha256_fingerprint_randomart->setText(
            QString::fromStdString(inputleap::create_fingerprint_randomart(fingerprint_sha256.data)));

    QString explanation;
    if (type == AppRole::Server) {
        explanation = tr("Compare this code with the fingerprint shown on the other "
                         "computer. If they match, choose Trust and connect. Only "
                         "approve computers you recognize on a trusted network.");
    } else {
        explanation = tr("Compare this code with the fingerprint shown on the main "
                         "computer. If they match, choose Trust and connect. Only "
                         "approve computers you recognize on a trusted network.");
    }
    ui_->label_explanation->setText(explanation);
}

FingerprintAcceptDialog::~FingerprintAcceptDialog() = default;
