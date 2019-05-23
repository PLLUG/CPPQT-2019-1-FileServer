#include "htmlcontentgenerator.h"
#include "filesystemmodel.h"
#include <Mustache\mustache.hpp>
#include <fstream>

//Configuration hTMLGenerator;
//DataModel item1;

<<<<<<< HEAD

struct FileSystemItems
{
    std::string name;
    bool isFolder;
};

std::vector<FileSystemItems> fsItemsList = {{"..", false},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"Test Folder", true},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false},
                                            {"file.txt", false}
                                           };

HTMLContentGenerator::~HTMLContentGenerator()
{

}

std::string HTMLContentGenerator::generate(const std::string &path)
{
    //return mustasheTemplate;

    std::string mustasheTemplate{""};
    std::ifstream templateFile;

    templateFile.open("./template.html");
    if(!templateFile.is_open())
    {
        std::cout<<"file \"template.html\" not found"<<std::endl;
    }
    else
    {
        std::string fileLine;
        while (!templateFile.eof())
         {
             std::getline(templateFile, fileLine);
             mustasheTemplate+=fileLine;
         }
    }

    //const bool mShowIconsColumn = true, mShowSizeColumn = true, mShowDetailsConst = true;
    kainjow::mustache::mustache tmpl{mustasheTemplate};

    kainjow::mustache::data mustashe{};

    mustashe.set("showIcons", mShowIconsColumn ? kainjow::mustache::data::type::bool_true
                                              : kainjow::mustache::data::type::bool_false);
    mustashe.set("showSize", mShowSizeColumn ? kainjow::mustache::data::type::bool_true
                                            : kainjow::mustache::data::type::bool_false);
    mustashe.set("showDetails", mShowDetailsConst ? kainjow::mustache::data::type::bool_true
                                                 : kainjow::mustache::data::type::bool_false);


    kainjow::mustache::data iconsListMustashe{kainjow::mustache::data::type::list};
    kainjow::mustache::data fileNamesListMustashe{kainjow::mustache::data::type::list};
    kainjow::mustache::data sizesListMustashe{kainjow::mustache::data::type::list};
    kainjow::mustache::data detailsListMustashe{kainjow::mustache::data::type::list};

    kainjow::mustache::data dirEntryListMustashe{kainjow::mustache::data::type::list};
    for (int fileIndex = 0; fileIndex < model()->count();  fileIndex++)
    {
        kainjow::mustache::data dirEntryMustashe;

        dirEntryMustashe.set("showIcons", mShowIconsColumn ? kainjow::mustache::data::type::bool_true
                                                          : kainjow::mustache::data::type::bool_false);

        // File Icon
        if (mShowIconsColumn)
        {
            dirEntryMustashe.set("showIcons", kainjow::mustache::data::type::bool_true);

            if (!model()->isDir(fileIndex))
            {
                if (model()->name(fileIndex) != "..")
                {
                    dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-sticky-note"></i>)");
                }
                else
                {
                    dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-level-up"></i>)");
                }
            }
            else
            {
                dirEntryMustashe.set("fileIcon", R"(<i class="fa fa-folder"></i>)");
            }
        }
        else
        {
            dirEntryMustashe.set("showIcons", kainjow::mustache::data::type::bool_false);
        }

        // File Name
        dirEntryMustashe.set("fileName", model()->name(fileIndex));
        dirEntryMustashe.set("fileIndex", std::to_string(fileIndex));


        // File Size
        if (mShowSizeColumn)
        {
            dirEntryMustashe.set("showSize", kainjow::mustache::data::type::bool_true);

            if (!model()->isDir(fileIndex) && model()->name(fileIndex) != "..")
            {
                dirEntryMustashe.set("fileSize", model()->sizeString(fileIndex));
            }
            else
            {
                dirEntryMustashe.set("fileSize", "-");
            }
        }
        else
        {
            dirEntryMustashe.set("showSize", kainjow::mustache::data::type::bool_false);
        }

        // File details

        //std::string detailsString="details";

        if (mShowDetailsConst)
        {
            dirEntryMustashe.set("showDetails", kainjow::mustache::data::type::bool_true);

            if (!model()->isDir(fileIndex) && model()->name(fileIndex) != "..")
            {
                //dirEntryMustashe.set("fileDetails", "fileDetails");
                dirEntryMustashe.set("hideON", "on");          
                dirEntryMustashe.set("fName", model()->name(fileIndex));                
                dirEntryMustashe.set("fSize", model()->sizeString(fileIndex));
                dirEntryMustashe.set("lastWritetTyime", model()->fileLastWriteTime(fileIndex));
            }
            else
            {
                dirEntryMustashe.set("fileDetails", "-");
                dirEntryMustashe.set("colorLink", "style='color:#000000'");
            }
        }
        else
        {
            dirEntryMustashe.set("showDetails", kainjow::mustache::data::type::bool_false);
        }

        dirEntryListMustashe << dirEntryMustashe;
    }

    mustashe.set("dirEntryList", dirEntryListMustashe);

    return tmpl.render(mustashe);

}

void HTMLContentGenerator::setConfiguration(Configuration configuration)
{
    mShowSizeColumn=configuration.isFileSizeColumnVisible();
    mShowIconsColumn=configuration.isIconColumnVisible();
    mShowDetailsConst=configuration.isDetailedInfoColumnVisible();
    mFSizeDisplayMode=configuration.fsizeDisplayingMode();
}
