package devrss.hmtri.vn.data;

import org.json.JSONObject;

/**
 * Created by hmtri on 11/15/2016.
 */
public interface JSONPopulator {
    void populate(JSONPopulator data);
    JSONObject toJSON();
}

