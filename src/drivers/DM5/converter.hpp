#pragma once

#ifndef CONVERTER_HPP
#define CONVERTER_HPP

// simplified & traditional is obtained from
// https://github.com/zachary822/chinese-converter.git
// Thanks to the original author

#include <codecvt>
#include <locale>

using namespace std;

class Converter {

public:
  string toSimplified(const string &text) {

    wstring wide = this->wstringConverter.from_bytes(text);

    wstring result;

    for (const wchar_t &c : wide) {
      // find and replace characters in simplified text
      // keep it if not found
      size_t index = traditional.find(c);
      result += index == string::npos ? c : simplified[index];
    }

    return this->wstringConverter.to_bytes(result);
  }

private:
// disable warning for deprecated functions
// which don't have standardized replacements
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wdeprecated-declarations"
  wstring_convert<codecvt_utf8_utf16<wchar_t>> wstringConverter;
#pragma GCC diagnostic pop

  wstring traditional =
      L"鈀鈸罷壩撥缽剝餑鉑悖誖鵓博簙鎛餺駁卜蔔濼蘗擺襬唄敗桮杯盃鵯揹背貝狽鋇輩"
      L"備憊砲炮齙飽鴇寶刨鉋鮑報頒板闆鈑絆辦錛賁幫綁并併並徬謗鎊繃逼偪筆秘祕鉍"
      L"佛彿髴費痺痹幣斃閉畢嗶蓽篳蹕闢辟贔鱉別彆癟飆標鏢颮鑣錶表鰾編鯿邊籩貶苄"
      L"芐緶辮辯變稟賓儐濱檳繽鑌瀕擯殯臏鬢髕餅補佈布鈽頗潑朴樸釙醱坏壞賠泡拋疱"
      L"皰盤蹣拼拚噴厖龐倣仿彷髣鵬紕鈹毘毗羆飄縹驃駢諞騙貧頻蘋苹顰嬪評蓱萍瓶缾"
      L"馮憑僕仆扑撲鋪譜媽螞嬤麻痲麼么馬嗎瑪碼罵无無模糢謨饃万萬襪袜沒歿脈霢麥"
      L"獏貘鏌驀買賣勱邁苺莓黴霉鎂謎貓犛氂錨鉚貿謀繆畝顢謾饅鰻瞞蠻滿縵鏝悶燜門"
      L"們捫鍆懣氓甿鋩懞濛蒙矇錳咪瞇眯彌瀰禰獼羋濔冪謐覓滅衊蔑緲廟謬綿腼靦緬面"
      L"麵緡閩閔憫黽澠銘鳴鉬鶩發髮閥罰琺緋飛誹鐨鯡廢復复複旛幡繙翻釩氾泛汎煩礬"
      L"販飯範范雰氛紛墳豶僨憤奮糞鈁魴紡訪丰豐風楓瘋諷鋒灃縫渢鳳賵麩膚紼紱輻鳧"
      L"縛縳輔頫俯撫訃駙鮒鰒負婦賻賦噠躂達韃騃獃呆貸隶隸靆紿駘帶島搗擣導禱盜幬"
      L"燾斗鬥豆荳餖竇讀酖鴆單鄲殫癉簞擔撣膽鉭羶膻啖啗憚彈誕當噹璫襠簹鐺党黨擋"
      L"檔讜碭盪蕩燈鐙鄧堤隄鏑滌适適敵糴覿詆締諦遞絰諜鰈帖踮跕疊鵰彫雕鯛鳥弔吊"
      L"釣銚調窵丟顛巔癲點鈿電澱墊釘頂錠訂飣鋌頓獨瀆櫝犢牘黷賭篤鍍奪鐸綞嚲馱飿"
      L"跢跺墮兌隊對懟緞鍛斷燉躉鈍飩噸遁遯鼕冬東凍棟動牠它鉈拓搨獺撻闥闒臺檯颱"
      L"台鮐鈦態韜弢搯掏絛濤鞀檮討頭貪嘽灘攤癱談錟壇罈譚鐔蕁曇襢袒歎嘆湯蹚趟鏜"
      L"糖餳醣儻燙謄藤籐騰緹題綈鵜體銻屜跕鐵齠條鰷鯈眺覜糶闐听聽廳頲禿塗涂圖釷"
      L"託托飥脫駝鴕鼉橢蘀籜頹蛻摶糰團魨衕同銅鮦僮童統慟拿挐拏內吶納訥鈉餒撓橈"
      L"鐃惱腦鬧柟楠難鈮兒儿鯢擬暱昵膩捻撚鎳岩喦巖嵒隉業聶攝囁躡鑷顳糱齧蔦裊嫋"
      L"嬝紐鈕鮎鯰輦攆輾唸念孃釀甯寧宁擰嚀獰檸聹濘駑挪挼儺諾農儂濃噥膿穠釹瘧謔"
      L"腊臘蠟蜡鑞樂瞭了來淶崍徠萊錸睞賚厲賴瀨癩籟累纍縲鐳誄壘淚類纇撈勞嘮嶗癆"
      L"銠絡澇摟婁僂漊嘍樓蔞窶螻耬髏嶁簍瘺瘻鏤嵐闌瀾攔斕欄蘭襴讕鑭藍襤籃攬欖纜"
      L"懶濫爛瑯琅閬鋃棱稜狸貍漓灕縭離蘺籬釐麗釃驪鸝鱺裡里鋰鯉禮鱧邐蒞鎘栗慄曆"
      L"厤歷瀝壢嚦櫪靂勵癘礪糲蠣櫟礫轢躒儷酈倆獵遼療繚鐐鷯釕溜霤鎦餾飀騮鶹劉瀏"
      L"鏐綹陸鷚簾帘連漣璉槤蓮褳鰱鐮奩憐聯蘞臉煉練鏈鍊殮斂襝瀲戀攣鄰轔鱗臨凜廩"
      L"懍賃藺躪涼諒糧兩魎輛鈴鴒齡淩凌綾鯪欞櫺靈領嶺嚕盧瀘廬壚爐鑪櫨蘆臚艫轤顱"
      L"鸕鱸滷鹵虜擄魯櫓淥祿綠錄籙轆輅賂鷺僇戮囉腡鏍騾羅儸玀蘿邏籮鑼裸臝駱犖巒"
      L"孌孿欒臠灤鑾鸞亂掄崙侖倫淪圇綸論輪龍瀧嚨瓏櫳蘢曨矓朧礱聾籠壟攏隴閭櫚驢"
      L"呂侶鋁屢褸縷慮濾鋝軋价價胳肐紇擱鴿閣合閤頜個蓋鉻該賅鈣給皜皓暠縞鎬攪誥"
      L"鋯构搆構鉤區溝緱苟茍夠詬覯購乾干幹榦桿杆尷稈趕赶紺贛灨亙杠槓岡剛崗綱鋼"
      L"韁戇賡綆骾鯁頸鈷鴣家傢轂詁谷穀餶鶻賈鵠蠱錮僱雇顧颳刮鴰蝸剮掛挂詿渦堝過"
      L"鍋蟈國摑幗槨拐枴窪洼閨鮭規溈媯龜歸軌匭詭貴匱櫃柜瞶會劊檜劌鱖鰥關觀管筦"
      L"館毋毌貫慣摜鑵罐鸛輥袞滾渾鯀广廣鄺獷紅龔宮鞏礦貢欬咳頦軻鈳顆殼剋克課錁"
      L"騍緙開豈剴凱愷塏闓鎧鍇愾考攷銬摳扣釦龕坎埳檻闞墾懇齦鈧骯肮閌硜羥傾鏗庫"
      L"褲嚳夸誇闊鞹擴塊儈澮噲鄶獪膾鱠闚窺虧巋餽饋潰憒蕢聵簣寬髖崑昆錕鯤捆綑閫"
      L"壼困睏誆誑況貺壙曠纊鉿蝦訶龢和核覈閡蝎蠍鶡齕闔嚇賀鶴還駭號蠔顥灝餱後后"
      L"鱟頇韓廠厂捍扞焊銲閈頷漢頏恆橫絎糊餬戲衚鬍胡鶘壺許滸沍冱戶滬獲穫護譁華"
      L"鏵嘩划劃驊樺畫嫿話夥伙貨禍鑊懷詼揮煇輝暉翬褘回迴虫蟲誨賄燬毀彙匯燴薈繪"
      L"繢闠噦穢翽諱懽歡驩環繯闤鐶鍰浣澣緩奐渙換喚煥瘓鯇閽葷餛琿諢鍠鰉黃謊哄鬨"
      L"轟紘閎訌葒鴻嶸黌嗊几幾机機飢饑嘰璣磯譏積勣績蹟跡齎躋齏雞羈伋汲級喫吃極"
      L"鶺借藉輯擊劇紀蟣濟擠記計騎際齊劑嚌薺霽鱭驥係系繫薊覬鯽繼夾鎵俠浹挾郟莢"
      L"蛺鋏頰鉀檟駕階結癤詰頡鮚擷傑杰訐節櫛潔誡屆鮫喬嬌驕鷦澆膠絞較鉸餃腳勦剿"
      L"僥撟矯繳嶠轎覺糾鳩鬮舊鷲奸姦鈃戔淺箋牋縑鶼鰜堅鰹間閑閒緘漸監艱殲韉揀譾"
      L"錢減筧戩儉撿檢瞼鹼鶱騫襉簡繭見荐薦鍵賤踐餞濺澗鐧艦鑒鑑劍諫筋觔寖浸僅謹"
      L"覲饉緊儘盡錦勁晉縉進燼藎贐姜薑將漿螿殭僵蔣槳獎講絳強彊醬鯨涇莖經荊驚剄"
      L"徑逕脛痙靚淨靜鏡競葅菹車駒據据鋸局侷齟舉櫸巨鉅詎颶懼屨決訣絕譎鵑鐫卷捲"
      L"睠眷絹雋鈞軍皸浚濬駿悽淒棲栖戚慼鏚溪谿榿緝旂旗頎蘄騏錡衹隻祇只鰭臍蠐啟"
      L"綺訖气氣棄磧鍥愜篋竊磽墝蹺鍬僑橋蕎礄譙翹鵲誚竅丘坵鞦秋鶖鰍賕虯韆千慳牽"
      L"謙鉛僉簽籤遷鋟鈐拑箝鉗潛繾譴蒨茜塹槧纖縴駸欽嶔親懃勤寢撳鏘搶嗆瑲槍鎗戧"
      L"蹌錆鏹嬙檣薔牆繈襁熗請鯖烴氫輕頃慶詘嶇敺驅軀趨鴝齲闃覷闕郤卻確确愨搉榷"
      L"闋詮輇銓踡蜷權顴綣勸煢惸窮瓊訢欣誒嘻譆犧攜席蓆習錫覡溼濕襲洒灑鰓璽潟瀉"
      L"細餼鬩峽狹陜陝硤轄舝廈協脅頁纈諧寫洩泄絏紲屧謝褻鴞綃銷梟蕭簫瀟蠨嘵髐囂"
      L"肴餚篠筱曉傚效嘯澩鵂修脩饈繡鏽僊仙秈姍祅祆躚銛鮮尟弦絃咸鹹啣銜嫻癇鷳賢"
      L"銑蜆嶮獫險蘚癬獮顯峴現莧餡羨線憲縣獻鋅尋釁廂緗鄉薌鑲驤詳餉饟鯗響饗嚮向"
      L"項蠁樣興騂鉶陘滎莕荇倖幸於于籲吁虛噓須鬚嘔餘余詡諝卹恤勗敘頊緒續學鱈喧"
      L"諠萱萲軒諼鏇旋懸選衒炫鉉絢勛熏燻詢馴潯鱘訊訓孫遜兇凶忷恟洶秖梔織執蟄縶"
      L"跖蹠質職擲躑阯址軹紙徵征緻致輊銍誌志制製置寘騭滯摯贄鷙幟識躓鑕遲觶扎紮"
      L"楂樝札劄閘鍘叉扠詐鮓笮筰搾榨柵摺折慴懾輒謫轍讋鍺這鷓著齋擇寨砦責債釗詔"
      L"櫂棹趙輈週周賙譸軸冑胄紂晝皺縐占佔沾霑覘譫氈鸇鱣斬嶄盞颭棧綻暫戰顫診貞"
      L"偵湞楨禎鍼針脣唇軫縝賑陣陳鎮張長漲帳脹賬鉦爭掙崢猙睜箏諍錚癥症證証幀鄭"
      L"硃朱誅銖諸豬瀦櫧櫫薯藷術朮築筑燭貯屬囑矚佇苧紵注註駐鑄撾諑濁鐲錐騅縋綴"
      L"墜贅顓專磚轉囀傳譔撰饌纂篹賺諄准準純妝莊裝樁壯狀終鍾鐘冢塚腫种種眾鴟馳"
      L"恥齒飭熾鍤奼詫剎硨徹釵儕冊蠆鈔綢讎儔疇籌躊丑醜摻攙嬋禪蟬纏讒鑱饞剗產剷"
      L"鏟滻諂闡囅蕆懺沈沉諶塵磣稱齔闖櫬襯讖閶錩鯧倀萇嚐嘗償場腸悵暢撐赬檉蟶誠"
      L"鋮棖傖懲騁齣出芻雛儲鋤耡廚櫥躕處礎絀觸齪輟綽搥捶鎚錘釧鶉蓴囪創瘡愴衝沖"
      L"寵銃屍尸鳲蝨虱詩師獅碩蝕時塒蒔鰣實駛鈰視貰試軾弒勢飾謚諡釋紗鯊殺鎩畬賒"
      L"捨舍設葉灄篩誰燒紹綬壽獸釤刪搧扇閃訕騸繕鱔贍紳詵参參諗審瀋嬸腎滲傷殤觴"
      L"賞昇升陞勝胜聲繩賸剩聖紓輸書樞攄贖數倏儵樹豎說帥爍鑠稅閂順驦雙熱嬈蕘蟯"
      L"饒擾遶繞紝紉軔韌認飪讓銣蠕蝡縟蕊橤睿叡銳軟閏潤絨羢鎔頌榮蠑諮咨資緇輜錙"
      L"鯔茲鎡貲齜眥漬臢咱偺雜則鰂嘖幘簀賾賊澤庂仄側災載糟蹧鑿棗繰皂皁噪譟諏鯫"
      L"鄒謅騶驟攢趲鏨讚贊酇瓚譖贓臟髒駔繒贈鏃組詛躦鑽纘鱒從縱蹤傯總瘲呲詞餈鶿"
      L"辭廁賜測惻筴纔才財寀采採綵彩騲草湊輳驂殘慚蠶慘燦倉滄蒼艙層觕粗麤錯鹺銼"
      L"縗淬焠攛躥竄蔥聰驄樅蓯叢緦鍶颸廝絲鷥螄駟飼颯薩銫嗇穡澀賽騷繅掃搜蒐鎪餿"
      L"颼擻藪毿傘繖糝喪顙蘇囌甦穌泝溯訴縮肅驌鷫謖簑蓑嗩瑣鎖綏雖隨誶歲酸痠猻蓀"
      L"筍損松鬆崧嵩慫訟誦錒醃腌訛鋨鵝額惡噁阨厄扼搤軛諤鍔顎鶚齶餓堊啞鱷閼挨捱"
      L"磑皚噯藹靄愛嬡璦曖靉礙驁鼇鰲殀夭媼襖奧嶴漚歐毆甌謳鷗銨庵菴鵪陰諳暗闇晻"
      L"鮞鉺餌爾邇貳銥醫毉鷖禕迤迆詒貽飴誼頤迻移儀遺釔螘蟻艤檥軼縊鎰鷁藝囈異義"
      L"議億憶鐿詣懌嶧繹譯驛瘞鴉鴨亞椏枒壓氬婭錏訝禦御爺野埜咽嚥謁鄴燁曄靨饁崖"
      L"厓喲殽淆堯嶢軺搖瑤遙謠颻鰩窯藥葯燿耀鑰鷂优優憂尤尢魷鈾遊游郵猶蕕銪祐佑"
      L"誘閹慇殷煙菸厭懨燕讌閻閆檐簷顏嚴鹽揜掩兗鼴厴魘黶儼喭諺焰燄硯雁鴈贗饜驗"
      L"讞釅豔灩裀茵銦駰銀淫婬飲隱癮廕蔭暈憖鴦痒癢颺揚陽煬楊暘瘍鍚養鶯應鷹嬰甖"
      L"罌攖嚶瓔櫻纓鸚塋熒瑩螢縈營瀅瀠贏蠅潁穎癭汙誣烏嗚鄔鎢鋙吳蕪捂摀鵡廡憮嘸"
      L"嫵務霧騖塢誤媧膃萵窩臥齷為韋幃圍違闈維濰諉鮪偉煒瑋葦緯韙偽餵喂蝟謂衛彎"
      L"灣紈頑挽輓綰溫轀鰮紋聞閿穩問網网輞甕瓮罋紆與諛輿璵歟踰逾覦娛魚漁俁語齬"
      L"嶼傴鈺欲慾鵒郁鬱愈瘉癒諭閾馭飫鷸預澦譽獄嫗約鉞嶽岳悅閱粵躍鴛鵷淵鳶黿園"
      L"轅員圓隕緣櫞遠願愿氳贇雲云沄澐蕓芸紜勻鄖篔殞韻惲鄆運鶤慍醞韞蘊噰嗈雍雝"
      L"癰傭佣鏞擁顒詠涌湧踴踊";

  wstring simplified =
      L"钯钹罢坝拨钵剥饽铂悖悖鹁博博镈馎驳卜卜泺蘖摆摆呗败杯杯杯鹎背背贝狈钡辈"
      L"备惫炮炮龅饱鸨宝刨刨鲍报颁板板钣绊办锛贲帮绑并并并彷谤镑绷逼逼笔秘秘铋"
      L"佛佛佛费痹痹币毙闭毕哔荜筚跸辟辟赑鳖别别瘪飙标镖飑镳表表鳔编鳊边笾贬苄"
      L"苄缏辫辩变禀宾傧滨槟缤镔濒摈殡膑鬓髌饼补布布钸颇泼朴朴钋酦坏坏赔辔抛疱"
      L"疱盘蹒拼拼喷庞庞仿仿仿仿鹏纰铍毗毗罴飘缥骠骈谝骗贫频苹苹颦嫔评萍萍瓶瓶"
      L"冯凭仆仆扑扑铺谱妈蚂嬷麻麻么么马吗玛码骂无无模模谟馍万万袜袜没殁脉霡麦"
      L"貘貘镆蓦买卖劢迈莓莓霉霉镁谜猫牦牦锚铆贸谋缪亩颟谩馒鳗瞒蛮满缦镘闷焖门"
      L"们扪钔懑氓氓铓蒙蒙蒙蒙锰梦眯眯弥弥祢猕芈沵幂谧觅灭蔑蔑缈庙谬绵腼腼缅面"
      L"面缗闽闵悯黾渑铭鸣钼鹜发发阀罚珐绯飞诽镄鲱废复复复幡幡翻翻钒泛泛泛烦矾"
      L"贩饭范范氛氛纷坟豮偾愤奋粪钫鲂纺访丰丰风枫疯讽锋沣缝沨凤赗麸肤绋绂辐凫"
      L"缚缚辅俯俯抚讣驸鲋鳆负妇赙赋哒跶达鞑呆呆呆贷隶隶叇绐骀带岛捣捣导祷盗帱"
      L"焘斗斗豆豆饾窦读鸩鸩单郸殚瘅箪担掸胆钽膻膻啖啖惮弹诞当当珰裆筜铛党党挡"
      L"档谠砀荡荡灯镫邓堤堤镝涤适适敌籴觌诋缔谛递绖谍鲽踮踮踮叠雕雕雕鲷鸟吊吊"
      L"钓铫调窎丢颠巅癫点钿电淀垫钉顶锭订饤铤顿独渎椟犊牍黩赌笃镀夺铎缍亸驮饳"
      L"跺跺堕兑队对怼缎锻断炖趸钝饨吨遁遁冬冬东冻栋动它它铊拓拓獭挞闼阘台台台"
      L"台鲐钛态韬韬掏掏绦涛鼗梼讨头贪啴滩摊瘫谈锬坛坛谭镡荨昙袒袒叹叹汤趟趟镗"
      L"糖糖糖傥烫誊藤藤腾缇题绨鹈体锑屉贴铁龆条鲦鲦眺眺粜阗听听厅颋秃涂涂图钍"
      L"托托饦脱驼鸵鼍椭萚箨颓蜕抟团团鲀同同铜鲖童童统恸拿拿拿内呐纳讷钠馁挠桡"
      L"铙恼脑闹楠楠难铌儿儿鲵拟昵昵腻捻捻镍岩岩岩岩陧业聂摄嗫蹑镊颞糵啮茑袅袅"
      L"袅纽钮鲇鲶辇撵辗念念娘酿宁宁宁拧咛狞柠聍泞驽挪挪傩诺农侬浓哝脓秾钕疟谑"
      L"腊腊蜡蜡镴乐了了来涞崃徕莱铼睐赉厉赖濑癞籁累累缧镭诔垒泪类颣捞劳唠崂痨"
      L"铑络涝搂娄偻溇喽楼蒌窭蝼耧髅嵝篓瘘瘘镂岚阑澜拦斓栏兰襕谰镧蓝褴篮览揽榄"
      L"懒滥烂琅琅阆锒棱棱狸狸漓漓缡离蓠篱厘丽酾骊鹂鲡里里锂鲤礼鳢逦莅镉栗栗历"
      L"历历沥坜呖枥雳励疠砺粝蛎栎砾轹跞俪郦俩猎辽疗缭镣鹩钌溜溜镏馏飗骝鹠刘浏"
      L"镠绺陆鹨帘帘连涟琏梿莲裢鲢镰奁怜联蔹脸炼练链链殓敛裣潋恋挛邻辚鳞临凛廪"
      L"懔赁蔺躏凉谅粮两魉辆铃鸰龄凌凌绫鲮棂棂灵领岭噜卢泸庐垆炉炉栌芦胪舻轳颅"
      L"鸬鲈卤卤虏掳鲁橹渌禄绿录箓辘辂赂鹭戮戮啰脶镙骡罗㑩猡萝逻箩锣裸裸骆荦峦"
      L"娈孪栾脔滦銮鸾乱抡仑仑伦沦囵纶论轮龙泷咙珑栊茏昽胧胧砻聋笼垄拢陇闾榈驴"
      L"吕侣铝屡褛缕虑滤锊轧价价胳胳纥搁鸽阁合合颌个盖铬该赅钙给皓皓皓缟镐搅诰"
      L"锆构构构钩区沟缑苟苟够诟觏购干干干干杆杆尴秆赶赶绀赣赣亘杠杠冈刚岗纲钢"
      L"缰戆赓绠鲠鲠颈钴鸪家家毂诂谷谷馉鹘贾鹄蛊锢雇雇顾刮刮鸹蜗剐挂挂诖涡埚过"
      L"锅蝈国掴帼椁拐拐洼洼闺鲑规沩妫龟归轨匦诡贵匮柜柜瞆会刽桧刿鳜鳏关观管管"
      L"馆毋毋贯惯掼罐罐鹳辊衮滚浑鲧广广邝犷红龚宫巩矿贡咳咳颏轲钶颗壳克克课锞"
      L"骒缂开岂剀凯恺垲闿铠锴忾考考铐抠扣扣龛坎坎槛阚垦恳龈钪肮肮闶硁羟倾铿库"
      L"裤喾夸夸阔鞟扩块侩浍哙郐狯脍鲙窥窥亏岿馈馈溃愦蒉聩篑宽髋昆昆锟鲲捆捆阃"
      L"壸困困诓诳况贶圹旷纩铪虾诃和和核核阂蝎蝎鹖龁阖吓贺鹤还骇号蚝颢灏糇后后"
      L"鲎顸韩厂厂捍捍焊焊闬颔汉颃恒横绗糊糊戏胡胡胡鹕壶许浒冱冱户沪获获护华华"
      L"哗哗划划铧桦画婳话伙伙货祸镬怀诙挥辉辉晖翚袆回回虫虫诲贿毁毁汇汇烩荟绘"
      L"缋阓哕秽翙讳欢欢欢环缳阛镮锾浣浣缓奂涣换唤焕痪鲩阍荤馄珲诨锽鳇黄谎哄哄"
      L"轰纮闳讧荭鸿嵘黉唝几几机机饥饥叽玑矶讥积积绩迹迹赍跻齑鸡羁汲汲级吃吃极"
      L"鹡借借辑击剧纪虮济挤记计骑际齐剂哜荠霁鲚骥系系系蓟觊鲫继夹镓侠浃挟郏荚"
      L"蛱铗颊钾槚驾阶结疖诘颉鲒撷杰杰讦节栉洁诫届鲛乔娇骄鹪浇胶绞较铰饺脚剿剿"
      L"侥挢矫缴峤轿觉纠鸠阄旧鹫奸奸钘戋浅笺笺缣鹣鳒坚鲣间闲闲缄渐监艰歼鞯拣谫"
      L"钱减笕戬俭捡检睑碱骞骞裥简茧见荐荐键贱践饯溅涧锏舰鉴鉴剑谏筋筋浸浸仅谨"
      L"觐馑紧尽尽锦劲晋缙进烬荩赆姜姜将浆螀僵僵蒋桨奖讲绛强强酱鲸泾茎经荆惊刭"
      L"径径胫痉靓净静镜竞菹菹车驹据据锯局局龃举榉巨巨讵飓惧屦决诀绝谲鹃镌卷卷"
      L"眷眷绢隽钧军皲浚浚骏凄凄栖栖戚戚戚溪溪桤缉旗旗颀蕲骐锜只只只只鳍脐蛴启"
      L"绮讫气气弃碛锲惬箧窃硗硗跷锹侨桥荞硚谯翘鹊诮窍丘丘秋秋鹙鳅赇虬千千悭牵"
      L"谦铅佥签签迁锓钤钳钳钳潜缱谴茜茜堑椠纤纤骎钦嵚亲勤勤寝揿锵抢呛玱枪枪戗"
      L"跄锖镪嫱樯蔷墙襁襁炝请鲭烃氢轻顷庆诎岖驱驱躯趋鸲龋阒觑阙却却确确悫榷榷"
      L"阕诠辁铨蜷蜷权颧绻劝茕茕穷琼欣欣诶嘻嘻牺携席席习锡觋湿湿袭洒洒鳃玺泻泻"
      L"细饩阋峡狭陕陕硖辖辖厦协胁页缬谐写泄泄绁绁屟谢亵鸮绡销枭萧箫潇蟏哓骁嚣"
      L"肴肴筱筱晓效效啸泶鸺修修馐绣锈仙仙籼姗祆祆跹铦鲜鲜弦弦咸咸衔衔娴痫鹇贤"
      L"铣蚬崄猃险藓癣狝显岘现苋馅羡线宪县献锌寻衅厢缃乡芗镶骧详饷饷鲞响飨向向"
      L"项蚃样兴骍铏陉荥荇荇幸幸于于吁吁虚嘘须须呕余余诩谞恤恤勖叙顼绪续学鳕喧"
      L"喧萱萱轩谖旋旋悬选炫炫铉绚勋熏熏询驯浔鲟讯训孙逊凶凶恟恟汹祇栀织执蛰絷"
      L"跖跖质职掷踯址址轵纸征征致致轾铚志志制制置置骘滞挚贽鸷帜识踬锧迟觯扎扎"
      L"楂楂札札闸铡叉叉诈鲊笮笮榨榨栅折折慑慑辄谪辙詟锗这鹧着斋择寨寨责债钊诏"
      L"棹棹赵辀周周赒诪轴胄胄纣昼皱绉占占沾沾觇谵毡鹯鳣斩崭盏飐栈绽暂战颤诊贞"
      L"侦浈桢祯针针唇唇轸缜赈阵陈镇张长涨帐胀账钲争挣峥狰睁筝诤铮症症证证帧郑"
      L"朱朱诛铢诸猪潴槠橥薯薯术术筑筑烛贮属嘱瞩伫苎纻注注驻铸挝诼浊镯锥骓缒缀"
      L"坠赘颛专砖转啭传撰撰馔纂纂赚谆准准纯妆庄装桩壮状终钟钟冢冢肿种种众鸱驰"
      L"耻齿饬炽锸姹诧刹砗彻钗侪册虿钞绸雠俦畴筹踌丑丑掺搀婵禅蝉缠谗镵馋刬产铲"
      L"铲浐谄阐冁蒇忏沉沉谌尘碜称龀闯榇衬谶阊锠鲳伥苌尝尝偿场肠怅畅撑赪柽蛏诚"
      L"铖枨伧惩骋出出刍雏储锄锄厨橱蹰处础绌触龊辍绰捶捶锤锤钏鹑莼囱创疮怆冲冲"
      L"宠铳尸尸鸤虱虱诗师狮硕蚀时埘莳鲥实驶铈视贳试轼弑势饰谥谥释纱鲨杀铩畲赊"
      L"舍舍设叶滠筛谁烧绍绶寿兽钐删扇扇闪讪骟缮鳝赡绅诜参参谂审沈婶肾渗伤殇觞"
      L"赏升升升胜胜声绳剩剩圣纾输书枢摅赎数倏倏树竖说帅烁铄税闩顺骦双热娆荛蛲"
      L"饶扰绕绕纴纫轫韧认饪让铷蠕蠕缛蕊蕊睿睿锐软闰润绒绒镕颂荣蝾咨咨资缁辎锱"
      L"鲻兹镃赀龇眦渍臜咱咱杂则鲗啧帻箦赜贼泽仄仄侧灾载糟糟凿枣缲皂皂噪噪诹鲰"
      L"邹诌驺骤攒趱錾赞赞酂瓒谮赃脏脏驵缯赠镞组诅躜钻缵鳟从纵踪偬总疭综词糍鹚"
      L"辞厕赐测恻䇲才才财采采采彩彩草草凑辏骖残惭蚕惨灿仓沧苍舱层粗粗粗错鹾锉"
      L"缞淬淬撺蹿窜葱聪骢枞苁丛缌锶飔厮丝鸶蛳驷饲飒萨铯啬穑涩赛骚缫扫搜搜锼馊"
      L"飕擞薮毵伞伞糁丧颡苏苏苏稣溯溯诉缩肃骕鹔谡蓑蓑唢琐锁绥虽随谇岁酸酸狲荪"
      L"笋损松松嵩嵩怂讼诵锕腌腌讹锇鹅额恶恶厄厄扼扼轭谔锷颚鹗腭饿垩哑鳄阏挨挨"
      L"硙皑嗳蔼霭爱嫒瑷暧叆碍骜鳌鳌夭夭媪袄奥岙沤欧殴瓯讴鸥铵庵庵鹌阴谙暗暗暗"
      L"鲕铒饵尔迩贰铱医医鹥祎迤迤诒贻饴谊颐移移仪遗钇蚁蚁舣舣轶缢镒鹢艺呓异义"
      L"议亿忆镱诣怿峄绎译驿瘗鸦鸭亚桠桠压氩娅铔讶御御爷野野咽咽谒邺烨晔靥馌崖"
      L"崖哟淆淆尧峣轺摇瑶遥谣飖鳐窑药药耀耀钥鹞优优忧尤尤鱿铀游游邮犹莸铕佑佑"
      L"诱阉殷殷烟烟厌恹燕燕阎阎檐檐颜严盐掩掩兖鼹厣魇黡俨彦谚焰焰砚雁雁赝餍验"
      L"谳酽艳滟茵茵铟骃银淫淫饮隐瘾荫荫晕慭鸯痒痒扬扬阳炀杨旸疡钖养莺应鹰婴罂"
      L"罂撄嘤璎樱缨鹦茔荧莹萤萦营滢潆赢蝇颍颖瘿污诬乌呜邬钨铻吴芜捂捂鹉庑怃呒"
      L"妩务雾骛坞误娲腽莴窝卧龌为韦帏围违闱维潍诿鲔伟炜玮苇纬韪伪喂喂猬谓卫弯"
      L"湾纨顽挽挽绾温辒鳁纹闻阌稳问网网辋瓮瓮瓮纡与谀舆玙欤逾逾觎娱鱼渔俣语龉"
      L"屿伛钰欲欲鹆郁郁愈愈愈谕阈驭饫鹬预滪誉狱妪约钺岳岳悦阅粤跃鸳鹓渊鸢鼋园"
      L"辕员圆陨缘橼远愿愿氲赟云云沄沄芸芸纭匀郧筼殒韵恽郓运鹍愠酝韫蕴嗈嗈雍雍"
      L"痈佣佣镛拥颙咏涌涌踊踊";
};

#endif