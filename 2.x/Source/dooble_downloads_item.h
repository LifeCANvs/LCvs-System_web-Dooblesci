/*
** Copyright (c) 2008 - present, Alexis Megas.
** All rights reserved.
**
** Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions
** are met:
** 1. Redistributions of source code must retain the above copyright
**    notice, this list of conditions and the following disclaimer.
** 2. Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
** 3. The name of the author may not be used to endorse or promote products
**    derived from Dooble without specific prior written permission.
**
** DOOBLE IS PROVIDED BY THE AUTHOR ``AS IS'' AND ANY EXPRESS OR
** IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES
** OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE DISCLAIMED.
** IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR ANY DIRECT, INDIRECT,
** INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT
** NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
** DOOBLE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#ifndef dooble_downloads_item_h
#define dooble_downloads_item_h

#include <QAtomicInteger>
#include <QTime>
#include <QPointer>
#include <QUrl>
#include <QWidget>

#include "ui_dooble_downloads_item.h"

class QWebEngineDownloadItem;

class dooble_downloads_item: public QWidget
{
  Q_OBJECT

 public:
  dooble_downloads_item(QWebEngineDownloadItem *download,
			qintptr oid,
			QWidget *parent);
  dooble_downloads_item(const QString &file_name,
			const QString &information,
			const QUrl &url,
			qintptr oid,
			QWidget *parent);
  ~dooble_downloads_item();
  QUrl url(void) const;
  bool is_finished(void) const;
  qintptr oid(void) const;

 private:
  QTime m_last_time;
  QPointer<QWebEngineDownloadItem> m_download;
  QUrl m_url;
  Ui_dooble_downloads_item m_ui;
  qintptr m_oid;
  qintptr m_last_bytes_received;
  qintptr m_rate;
  static QAtomicInteger<quintptr> s_db_id;
  void prepare_icons(void);
  void record(void);
  void record_information(void);

 private slots:
  void slot_cancel(void);
  void slot_download_progress(qintptr bytes_received, qintptr bytes_total);
  void slot_finished(void);
  void slot_settings_applied(void);
};

#endif
