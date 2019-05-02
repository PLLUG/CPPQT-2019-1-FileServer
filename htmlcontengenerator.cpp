#include "htmlcontentgenerator.h"
#include <Mustache\mustache.hpp>

//Configuration hTMLGenerator;
//DataModel item1;

std::string HTMLContentGenerator::generate(const std::string &path)
{
    return std::string();
//    kainjow::mustache::mustache tmpl{path};

//    kainjow::mustache::data mustashe{};
//    mustashe.set("showIcons", hTMLGenerator.isIconColumnVisible() ? kainjow::mustache::data::type::bool_true
//                                   : kainjow::mustache::data::type::bool_false);
//    mustashe.set("showSize", hTMLGenerator.isFileSizeColumnVisible() ? kainjow::mustache::data::type::bool_true
//                                   : kainjow::mustache::data::type::bool_false);
//    mustashe.set("showDetails", hTMLGenerator.isDetailedInfoColumnVisible() ? kainjow::mustache::data::type::bool_true
//                                   : kainjow::mustache::data::type::bool_false);


//    kainjow::mustache::data iconsListMustashe{kainjow::mustache::data::type::list};
//    kainjow::mustache::data fileNamesListMustashe{kainjow::mustache::data::type::list};
//    kainjow::mustache::data sizesListMustashe{kainjow::mustache::data::type::list};
//    kainjow::mustache::data detailsListMustashe{kainjow::mustache::data::type::list};

//    kainjow::mustache::data dirEntryListMustashe{kainjow::mustache::data::type::list};
//    for (const auto &item: hTMLGenerator.dir())
//    {
//        kainjow::mustache::data dirEntryMustashe;

//        dirEntryMustashe.set("showIcons", hTMLGenerator.isIconColumnVisible() ? kainjow::mustache::data::type::bool_true
//                                       : kainjow::mustache::data::type::bool_false);

//        // File Icon
//        if (hTMLGenerator.isIconColumnVisible())
//        {
//            dirEntryMustashe.set("showIcons", kainjow::mustache::data::type::bool_true);

//            if (!item.isFolder)
//            {
//                if (item.name != "..")
//                {
//                    dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-sticky-note"></i>)");
//                }
//                else
//                {
//                    dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-level-up"></i>)");
//                }
//            }
//            else
//            {
//                dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-folder"></i>)");
//            }
//        }
//        else
//        {
//            dirEntryMustashe.set("showIcons", kainjow::mustache::data::type::bool_false);
//        }

//        // File Name
//        dirEntryMustashe.set("fileName", item.name);

//        // File Size
//        if (hTMLGenerator.isFileSizeColumnVisible())
//        {
//            dirEntryMustashe.set("showSize", kainjow::mustache::data::type::bool_true);

//            if (!item.isFolder && item.name != "..")
//            {
//                dirEntryMustashe.set("fileSize", "1 K");
//            }
//            else
//            {
//                dirEntryMustashe.set("fileSize", "-");
//            }
//        }
//        else
//        {
//            dirEntryMustashe.set("showSize", kainjow::mustache::data::type::bool_false);
//        }

//        // File details
//        if (hTMLGenerator.isDetailedInfoColumnVisible())
//        {
//            dirEntryMustashe.set("showDetails", kainjow::mustache::data::type::bool_true);

//            if (!item.isFolder && item.name != "..")
//            {
//                dirEntryMustashe.set("fileDetails", "details");
//            }
//            else
//            {
//                dirEntryMustashe.set("fileDetails", "-");
//            }
//        }
//        else
//        {
//            dirEntryMustashe.set("showDetails", kainjow::mustache::data::type::bool_false);
//        }

//        dirEntryListMustashe << dirEntryMustashe;
//    }

//    mustashe.set("dirEntryList", dirEntryListMustashe);

    //    return tmpl.render(mustashe);
}

void HTMLContentGenerator::setConfiguration(Configuration configuration)
{

}
