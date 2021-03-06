/*
 * JsonDeserializer.h, part of VCMI engine
 *
 * Authors: listed in file AUTHORS in main folder
 *
 * License: GNU General Public License v2.0 or later
 * Full text of license available in license.txt file, in main folder
 *
 */
#pragma once

#include  "JsonSerializeFormat.h"

class JsonNode;

class JsonDeserializer: public JsonSerializeFormat
{
public:
	JsonDeserializer(const IInstanceResolver * instanceResolver_, JsonNode & root_);

	void serializeLIC(const std::string & fieldName, const TDecoder & decoder, const TEncoder & encoder, const std::vector<bool> & standard, std::vector<bool> & value) override;
	void serializeLIC(const std::string & fieldName, LIC & value) override;
	void serializeLIC(const std::string & fieldName, LICSet & value) override;
	void serializeString(const std::string & fieldName, std::string & value) override;

protected:
	void serializeInternal(const std::string & fieldName, boost::logic::tribool & value) override;
	void serializeInternal(const std::string & fieldName, si32 & value, const boost::optional<si32> & defaultValue, const TDecoder & decoder, const TEncoder & encoder)	override;
	void serializeInternal(const std::string & fieldName, std::vector<si32> & value, const TDecoder & decoder, const TEncoder & encoder) override;
	void serializeInternal(const std::string & fieldName, double & value, const boost::optional<double> & defaultValue) override;
	void serializeInternal(const std::string & fieldName, si64 & value, const boost::optional<si64> & defaultValue) override;
	void serializeInternal(const std::string & fieldName, si32 & value, const boost::optional<si32> & defaultValue, const std::vector<std::string> & enumMap) override;

private:
	void readLICPart(const JsonNode & part, const TDecoder & decoder, const bool val, std::vector<bool> & value);
	void readLICPart(const JsonNode & part, const TDecoder & decoder, std::set<si32> & value);
};
