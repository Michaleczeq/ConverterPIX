/*********************************************************************
 *           Copyright (C) 2017 mwl4 - All rights reserved           *
 *********************************************************************
 * File       : zipfs_file.h
 * Project    : ConverterPIX
 * Developers : Michal Wojtowicz (mwl450@gmail.com)
 			  : Piotr Krupa (piotrkrupa06@gmail.com)
 *********************************************************************/

#pragma once

#include "file.h"

class ZipFsFile : public File
{
public:
	ZipFsFile(const String &filepath, ZipFileSystem *filesystem, const class ZipEntry *entry);
	ZipFsFile(const ZipFsFile &) = delete;
	ZipFsFile(ZipFsFile &&) = delete;
	virtual ~ZipFsFile();

	ZipFsFile &operator=(const ZipFsFile &) = delete;
	ZipFsFile &operator=(ZipFsFile &&) = delete;

	virtual uint64_t write(const void *buffer, uint64_t elementSize, uint64_t elementCount) override;
	virtual uint64_t read(void *buffer, uint64_t elementSize, uint64_t elementCount) override;
	virtual uint64_t size() override;
	virtual bool seek(uint64_t offset, Attrib attr) override;
	virtual void rewind() override;
	virtual uint64_t tell() const override;
	virtual void flush() override;

private:
	String			m_filepath;
	ZipFileSystem * m_filesystem;
	z_stream		m_stream;
	uint64_t		m_position;

	const class ZipEntry *m_entry;

private:
	void inflateInitialize();
	void inflateDestroy();

	friend class ZipFileSystem;
};

/* eof */
