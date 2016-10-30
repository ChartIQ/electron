// Copyright (c) 2012 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#include "chrome/browser/browser_process.h"

#include "chrome/browser/printing/print_job_manager.h"
#include "chrome/browser/icon_manager.h"
#include "ui/base/l10n/l10n_util.h"

BrowserProcess* g_browser_process = NULL;

BrowserProcess::BrowserProcess()
    : print_job_manager_(new printing::PrintJobManager) {
  g_browser_process = this;

  icon_manager_.reset(new IconManager);
}

BrowserProcess::~BrowserProcess() {
  g_browser_process = NULL;
}

std::string BrowserProcess::GetApplicationLocale() {
  return l10n_util::GetApplicationLocale("");
}

printing::PrintJobManager* BrowserProcess::print_job_manager() {
  return print_job_manager_.get();
}

IconManager* BrowserProcess::icon_manager() {
  return icon_manager_.get();
}
